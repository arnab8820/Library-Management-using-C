//This file contains function to submit a book

void submit_book()
{
    int i,j,book_pos,found=0,no_book=1;
    char arr[12],book[100],c;
    struct book book1;
    //FILE *fp=fopen("temp.csv","r");
    for(i=0;i<12;i++)
        arr[i]='\0';
    cls();
    printf("\nBook submit");
    printf("\n================\n\n");
    for(i=0;i<4;i++)
    {
        if(user1.issue[i][1]!='\0')
        {
            no_book=0;
            break;
        }
    }
    if(no_book==1)
    {
        printf("\n\n\t\tYou don't have any books pending. Press any key to go back...");
        getch();
        return;
    }
    input:
    printf("\nEnter the isbn number of the book you want to submit: ");
    gets(arr);
    for(i=0;i<10;i++)
    {
        if(!isdigit(arr[i]))
        {
            printf("\nInvalid input!");
            goto input;
        }
    }
    for(i=0;i<4;i++)
    {
        if(strcmp(user1.issue[i],arr)==0)
        {
            found=1;
            book_pos=i;
            break;
        }
    }

    if(found=1)
    {
        rewind(bookdb);
        while(fgets(book,71,bookdb)!=NULL)
        {
            for(i=0;i<30;i++)
            {
                book1.author[i]='\0';
                book1.name[i]='\0';
                book1.isbn[i%11]='\0';
            }
            i=0;
            j=0;
            while(book[i]!=',')
            {
                book1.name[j]=book[i];
                i++;
                j++;
            }
            i++;
            j=0;
            while(book[i]!=',')
            {
                book1.author[j]=book[i];
                i++;
                j++;
            }
            i++;
            j=0;
            while(book[i]!='\n')
            {
                book1.isbn[j]=book[i];
                i++;
                j++;
            }
            if(strcmp(book1.isbn,user1.issue[book_pos])==0)
            {
                printf("\n\n  ISBN\t\t\tName\t\t\tAuthor");
                printf("\n---------------------------------------------------------------------------------");
                printf("\n%s\t\t%s\t\t\t%s",book1.isbn,book1.name,book1.author);
            }

        }
        printf("\n\nPress C to cancel or press any key to continue...");
        c=getch();
        if(c=='c'||c=='C')
            return;
        else
        {
            for(i=0;i<11;i++)
            {
                user1.issue[book_pos][i]='\0';
            }
        }
    }
    else
    {
        printf("\nBook not found!");
        getch();
        return;
    }

}

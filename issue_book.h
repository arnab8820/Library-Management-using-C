//This file contains the function to issue new book

void issue_book()
{
    //initialization
    int i,j,x,limit=1,book_pos,book_found=0;
    char arr[11],book[70],c;
    struct book book1;
    //printing header
    cls();
    printf("\nIssue book");
    printf("\n==============");
    //checking
    for(i=0;i<4;i++)
    {
        if(user1.issue[i][1]=='\0')
        {
            limit=0;
            break;
        }
    }
    book_pos=i;
    if(limit==0)
    {
        isbn:
        printf("\nEnter the 10 digit isbn of the book: ");
        gets(arr);
        for(i=0;arr[i]!='\0';i++)
        {
            if(isdigit(arr[i])==0)
            {
                printf("\nInvalid input!");
                goto isbn;
            }
        }
        rewind(bookdb);
        while(fgets(book,70,bookdb)!=NULL)
        {
            for(x=0;x<30;x++)
            {
                book1.author[x]='\0';
                book1.name[x]='\0';
                book1.isbn[x%11]='\0';
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
            if(strcmp(book1.isbn,arr)==0)
            {
                book_found=1;
                break;
            }
        }
        if(book_found==1)
        {
            cls();
            printf("\n%s\t%s\t%s",book1.isbn,book1.name,book1.author);
            printf("\n\nPress C to cancel or any key to continue issuing process...");
            c=getch();
            if(c=='c'||c=='C')
                return;
            else
            {
                strcpy(user1.issue[book_pos],book1.isbn);
                printf("\nBook successfully issued!");
                printf("\n\nPress any key to return to the main menu...");
                getch();
                return;
            }
        }
        else
        {
            printf("\nInvalid ISBN number entered. Please try again!");
            goto isbn;
        }
    }
    else
    {
        printf("\nYou have issued maximum number of books!");
        printf("\n\nPress any key to return to the main menu...");
        getch();
        return;
    }
}

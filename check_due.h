


void check_due()
{
    int i,j,x, null_count=0;
    char book[100];
    struct book book1;
    cls();
    printf("\nDue books");
    printf("\n=============");
    printf("\n\n  ISBN\t\t\tName\t\t\tAuthor");
    printf("\n---------------------------------------------------------------------------------");


    //checking due books
    for(x=0;x<4;x++)
    {
        if(user1.issue[x][1]=='\0') // if not null means that place is filled with book name, else will execute
        {
            null_count++;
            if(null_count==4)
            {
                printf("\n\n\t\tYou don't have any books pending. Press any key to go back...");
                getch();
                return;
            }
            continue;
        }
        else
        {
            rewind(bookdb);
            /* fetching the book details in the variable
               book which is of structure type
               and has varialbe
                  author
                  name
                  isbn
               so what we are gonna do is seperate the value
                and put it in respective variable
            */
            while(fgets(book,71,bookdb)!=NULL)
            {
                for(i=0;i<30;i++)  // book1 is temporary variable created here in this program
                {
                    book1.author[i]='\0';  //putting null in every location of book1 structure variable
                    book1.name[i]='\0';
                    book1.isbn[i%11]='\0';
                }
                
                //now seperating it, and putting it into temporaray variable
                // book1.name, book1.author, book1.isbn
                // after that we'll compare
                
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
                if(strcmp(book1.isbn,user1.issue[x])==0)
                {
                    printf("\n%s\t\t%s\t\t\t%s",book1.isbn,book1.name,book1.author);
                }
            }
        }
    }
    printf("\n\nPress any key to return to main menu...");
    getch();
}

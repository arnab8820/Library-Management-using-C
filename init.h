/* this file contains the initialization function */

void init()
{
    userdb=fopen("userdb.csv", "a+");
    bookdb=fopen("bookdb.csv", "r");
    if(userdb==NULL)
    {
        printf("\nUnable to open userdb.csv. It may not exist or is corrupted!");
        getch();
        exit(0);
    }
    if(bookdb==NULL)
    {
        printf("\nUnable to open bookdb.csv. It may not exist or is corrupted!");
        getch();
        exit(0);
    }
}

//This file contains welcome function

void welcome()
{
    cls();
    if(user1.mname[1]=='\0')
        printf("\t\t\t\tWelcome %s %s",user1.fname,user1.lname);
    else
        printf("\t\t\t\tWelcome %s %s %s",user1.fname,user1.mname,user1.lname);
    printf("\n\n\n\t\t\t\tPress any key to continue...");
    getch();
}

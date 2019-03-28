/*This file contains the  global data definitions*/

//user structure definition
/* 

   every user will have registration field, password, first name, second name, 
   middle name
   last name
   and issue , an array of 2 dimensional matrix
   each book of length 11 and maximum of 4 books can be issued 
   by the user
   
*/
struct user
{
    char reg[10];
    char password[10];
    char fname[20];
    char mname[20];
    char lname[20];
    char issue[4][11];
};
//ends here

//books structure definition

/*
  every book has it's name
    author name
    and it's 11 digit isbn number
    while issuing we make use of isbn number 
    user will be prompt to enter the isbn number, there is no other way
*/
struct book
{
    char name[30];
    char author[30];
    char isbn[11];
};
//ends here

//screen clearing function
//and setting some default text
void cls()
{
    system("cls");
    printf("\n\t\t\t\tLibrary Management System\t\t\t\t\n");
    printf("\n###############################################################################\n\n");

}
//Global variables and pointers are defined here
//creating two files, one userdatabase (userdb) and book database (bookdb) , 
// of pointer type becuase file declaration is of that way, pointer to file


FILE *userdb, *bookdb;

// creating a user1 of strucutre of user type, that we have declared above

struct user user1;

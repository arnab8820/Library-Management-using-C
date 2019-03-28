#include<stdio.h>
#include<conio.h>
#include<windows.h>

#include "datatype.h"
#include "init.h"
#include "login.h"
#include "register.h"
#include "welcome.h"
#include "check_due.h"
#include "issue_book.h"
#include "submit_book.h"
#include "logout.h"

void main()
{
    int l;
    char ch, ch2;
    cls();
    printf("\n\n\n\t\tInitializing. Please Wait...");
    //initializing program
    init();
    Sleep(2000);
    //printing main menu
    cls();
    while(1)
    {
        main_menu:
        cls();
        printf("\n\t\tMain Menu");
        printf("\n============================================");
        printf("\n\n1. Register\t2. Login\t3. Quit");
        printf("\n\nEnter your choice: ");
        ch=getche();
        if(ch<'1'||ch>'3')
        {
            printf("You have entered %c. Please enter correctly!", ch);
            getch();
            goto main_menu;
        }
        switch(ch)
        {
            case '1': regster();
                        break;
            case '2': if((l=login())==1)        //trying to log user in
                      {
                            welcome();
                            while(1)
                            {
                                user_menu:      //printing user menu
                                cls();
                                printf("\n\tServices available:");
                                printf("\n====================================================\n");
                                printf("\n1. ISSUE A BOOK                 2. RETURN A BOOK");
                                printf("\n3. CHECK DUE BOOKS              4. LOGOUT");
                                printf("\n\nEnter your choice: ");
                                ch2=getche();
                                if(ch2<'1'||ch2>'4')
                                {
                                    printf("\nYou have entered %c. Please enter correctly", ch2);
                                    printf("\nPress any key!");
                                    getch();
                                    goto user_menu;
                                }
                                switch(ch2)             //switching according to the choice of the user
                                {
                                    case '1': issue_book();
                                                break;
                                    case '2': submit_book();
                                                break;
                                    case '3': check_due();
                                                break;
                                    case '4': logout();
                                                break;

                                }
                            }
                      }
                      break;
            case '3': fclose(userdb);           //closing files and exiting
                      fclose(bookdb);
                      exit(0);

        }
    }
}

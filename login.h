/* This fie contains the login function */

int login()
{
    struct user temp;
    int i,j,x,y,flag=0;
    char ch, arr[200];
    cls();
    printf("\nUser Login");
    printf("\n==============\n\n");
    username:
    printf("\nEnter your Registration no.: ");
    gets(temp.reg);
    if(temp.reg[0]=='\0')
    {
        printf("\nInvalid Registration number!");
        goto username;
    }
    printf("\nEnter your password: ");
    i=0;
    while((ch=getch())!='\r')  //r means carriage return, we have used getch because character will
    //get replaced by other character and it will make an illusion of password entering scheme
    //just like entering data in password field in android, text fields and all
    
    {
        temp.password[i]=ch;
        printf("*");
        i++;
    }
    temp.password[i]='\0';  //addding null, becuase string terminated with a null
    //otherwise it won't make a valid string
    //it result in error

    //putting NULL in arr
    for(x=0;x<200;x++)
    {
        arr[x]='\0';
    }
    //ends here

    rewind(userdb);
    while(fgets(arr,200,userdb)!=NULL)  
    {
        //putting NULL to avoid garbage
        for(x=0;x<20;x++)
        {
            user1.reg[x%10]='\0';
            user1.password[x%10]='\0';
            user1.fname[x]='\0';
            user1.mname[x]='\0';
            user1.lname[x]='\0';
            user1.issue[0][x%11]='\0';
            user1.issue[1][x%11]='\0';
            user1.issue[2][x%11]='\0';
            user1.issue[3][x%11]='\0';
        }

        //ends here

        //separating data
        
        // and putting in respective data variable like user1.reg, user1.password, user1.fname, etc
        
        //everything is seperated by ',' because we are using csv file(comma sepearted value)
        i=0;
        j=0;
        while(arr[i]!=',')  
        {
            user1.reg[j]=arr[i];
            i++;
            j++;
        }
        j=0; // making it 0, because every character array starts from 0
        i++;  // i continues because we have fetched the entire data in one variable (string)
        //and everything is seperated by , .. so it continues
        while(arr[i]!=',')
        {
            user1.password[j]=arr[i];
            i++;
            j++;
        }
        j=0;
        i++;
        while(arr[i]!=',')
        {
            user1.fname[j]=arr[i];
            i++;
            j++;
        }
        j=0;
        i++;
        while(arr[i]!=',')
        {
            user1.mname[j]=arr[i];
            i++;
            j++;
        }
        j=0;
        i++;
        while(arr[i]!=',')
        {
            user1.lname[j]=arr[i];
            i++;
            j++;
        }
        j=0;
        i++;
        while(arr[i]!=',')
        {
            user1.issue[0][j]=arr[i];
            i++;
            j++;
        }
        j=0;
        i++;
        while(arr[i]!=',')
        {
            user1.issue[1][j]=arr[i];
            i++;
            j++;
        }
        j=0;
        i++;
        while(arr[i]!=',')
        {
            user1.issue[2][j]=arr[i];
            i++;
            j++;
        }
        j=0;
        i++;
        while(arr[i]!='\n')
        {
            user1.issue[3][j]=arr[i];
            i++;
            j++;
        }
        //all the data are put into respective variable
        

        //starting comparison between whatever user entered in registration number 
        //with the original value
        // temp.reg == user1.reg
        //if equal then we are comparing with password

        if(strcmp(temp.reg, user1.reg)==0)
        {
            if(strcmp(temp.password, user1.password)==0)
            {
                flag=1;
                return(1);
                break;
            }
            else
            {
                printf("\nInvalid password! Press any key to continue...");
                getch();
                return(0);
                break;
            }
        }
    }
    if(flag==0)
    {
        printf("\nInvalid username or password!");
        printf("\nPress any key to continue...");
        getch();
        return(0);
    }
}


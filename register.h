/* This file contains function for new user registration */

void regster()
{
    int x,y,i,j;
    char arr[120], arr2[9], ch, pass[10];
    //putting NULL to avoid garbage

    for(x=0;x<20;x++)
    {
        user1.reg[x%8]='\0';
        user1.password[x%10]='\0';
        user1.fname[x]='\0';
        user1.mname[x]='\0';
        user1.lname[x]='\0';
        pass[x%10]='\0';
    }

    for(x=0;x<4;x++)
    {
        for(y=0;y<10;y++)
        {
            user1.issue[x][y]='\0';
        }
    }
    //ends here

    //Starting registration

    cls();
    printf("\nUser Registration");
    printf("\n====================\n\n");

    //getting reg no
    reg_no:
    printf("\nEnter the registration number: ");
    gets(user1.reg);
    //check if already exists
    rewind(userdb);
    while(fgets(arr,200,userdb)!=NULL)
    {
        i=0;
        j=0;

        while(arr[i]!=',')
        {
            arr2[i]=arr[j];
            i++;
            j++;
        }
        arr2[i]='\0';
        if(strcmp(user1.reg,arr2)==0)
        {
            printf("\nRegistration number already exists!");
            goto reg_no;
        }
    }

    //getting password
    pass:
    for(x=0;x<10;x++)
    {

        user1.password[x]='\0';
        pass[x]='\0';
    }
    printf("\nEnter your password: ");
    i=0;
    while((ch=getch())!='\r')
    {
        user1.password[i]=ch;
        printf("*");
        i++;
    }

    printf("\nEnter your password again: ");
    i=0;
    while((ch=getch())!='\r')
    {
        pass[i]=ch;
        printf("*");
        i++;
    }

    //check for correct password
    if(strcmp(user1.password,pass)!=0)
    {
        printf("\nPassword does not match!");
        goto pass;
    }

    //getting the name of the user
    printf("\nEnter your first name: ");
    gets(user1.fname);
    printf("\nEnter your middle number: ");
    gets(user1.mname);
    printf("\nEnter your last name: ");
    gets(user1.lname);

    //confirming the details
    cls();
    printf("\nConfirm the detail:");
    printf("\n======================");
    printf("\n\nReg no.: %s",user1.reg);
    printf("\nPassword: ");
    for(i=0;user1.password[i]!='\0';i++)
    {
        printf("*");
    }
    printf("\nFirstname: %s\nMiddlename: %s\nLastname: %s",user1.fname,user1.mname,user1.lname);
    printf("\n\nPress E to edit any other key to continue...");

    //CHECK IF USER NEEDS TO EDIT THE DETAIL
    ch=getch();
    if(ch=='e'||ch=='E')
        goto reg_no;

    fprintf(userdb,"%s,%s,%s,%s,%s,%s,%s,%s,%s\n",user1.reg,user1.password,user1.fname,user1.mname,user1.lname,user1.issue[0],user1.issue[1],user1.issue[2],user1.issue[3]);
    printf("\nUser registration successful!");
}

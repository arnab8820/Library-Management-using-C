/*this file for logout function*/
void write_db()
{
    int k,i,j;
    struct user temp2;
    char arr[200];
    FILE *temp=fopen("temp.csv","w");
    rewind(userdb);
    while(fgets(arr,130,userdb)!=NULL)
    {
        //putting NULL to avoid garbage
        for(k=0;k<20;k++)
        {
            temp2.reg[k%10]='\0';
            temp2.password[k%10]='\0';
            temp2.fname[k]='\0';
            temp2.mname[k]='\0';
            temp2.lname[k]='\0';
            temp2.issue[0][k%11]='\0';
            temp2.issue[1][k%11]='\0';
            temp2.issue[2][k%11]='\0';
            temp2.issue[3][k%11]='\0';
        }

        //ends here

        //separating data
        i=0;
        j=0;
        while(arr[i]!=',')
        {
            temp2.reg[j]=arr[i];
            i++;
            j++;
        }
        j=0;
        i++;
        while(arr[i]!=',')
        {
            temp2.password[j]=arr[i];
            i++;
            j++;
        }
        j=0;
        i++;
        while(arr[i]!=',')
        {
            temp2.fname[j]=arr[i];
            i++;
            j++;
        }
        j=0;
        i++;
        while(arr[i]!=',')
        {
            temp2.mname[j]=arr[i];
            i++;
            j++;
        }
        j=0;
        i++;
        while(arr[i]!=',')
        {
            temp2.lname[j]=arr[i];
            i++;
            j++;
        }
        j=0;
        i++;
        while(arr[i]!=',')
        {
            temp2.issue[0][j]=arr[i];
            i++;
            j++;
        }
        j=0;
        i++;
        while(arr[i]!=',')
        {
            temp2.issue[1][j]=arr[i];
            i++;
            j++;
        }
        j=0;
        i++;
        while(arr[i]!=',')
        {
            temp2.issue[2][j]=arr[i];
            i++;
            j++;
        }
        j=0;
        i++;
        while(arr[i]!='\n')
        {
            temp2.issue[3][j]=arr[i];
            i++;
            j++;
        }
        //separating ends here

        //starting comparison and updating db
        if(strcmp(temp2.reg,user1.reg)==0)
        {
            continue;
        }
        else
        {
            fprintf(temp,"%s,%s,%s,%s,%s,%s,%s,%s,%s\n",temp2.reg,temp2.password,temp2.fname,temp2.mname,temp2.lname,temp2.issue[0],temp2.issue[1],temp2.issue[2],temp2.issue[3]);

        }
    }
    fprintf(temp,"%s,%s,%s,%s,%s,%s,%s,%s,%s\n",user1.reg,user1.password,user1.fname,user1.mname,user1.lname,user1.issue[0],user1.issue[1],user1.issue[2],user1.issue[3]);
    fclose(userdb);
    fclose(temp);
    fclose(bookdb);
    remove("userdb.csv");
    rename("temp.csv", "userdb.csv");

}
void logout()
{
    int i,j;
    char c;
    cls();
    printf("\nAre you sure you want to logout?\n");
    printf("\nIF YES PRESS (y) AND FOR NO (n)  : ");
    scanf("%c",&c);
    if(c=='y')
    {
        write_db();
        printf("\n\n\t\tYou have successfully logged out! Press any key to go to the main menu.");
        getch();
        for(i=0;i<20;i++)
        {
            user1.reg[i%10]='\0';
            user1.reg[i%10]='\0';
            user1.password[i%10]='\0';
            user1.fname[i]='\0';
            user1.mname[i]='\0';
            user1.lname[i]='\0';
            for(j=0;j<10;j++)
            {
                user1.issue[i%4][j]='\0';
            }

        }
        main();
    }
}

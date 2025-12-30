#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>

void accountcreated();
void login();
void accountlogin(char username1[]);
void display(char username1[]);
void transfer(char username1[]);
void checkbalance(char username2[]);
void logout();

struct detailes{
    int choice;
    char username[50];
    long int Adhaar_No[15];
    long int Phone_No[15];
    char Address[50];
    char Father_Name[50];
    char Mother_Name[50];
    char Type_account[10];
    char password[20];
    long int Amount;
};

void account()
{
    char password[20];
    int seek = 0;
    FILE *fp, *fu;
    struct detailes u1;

    system("cls");

    fp = fopen("username.txt", "ab");

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("Enter your Name: ");

    fgets(u1.username,50,stdin);

    int n = strlen(u1.username);

    if(u1.username[n-1] == '\n')
        u1.username[n-1] = '\0';

    printf("Enter your Adhaar Number: ");
    scanf("%d", &u1.Adhaar_No); 

    printf("Enter your Phone Number: +91-");
    scanf("%d", &u1.Phone_No);

    printf("Enter your Address: ");
    fgets(u1.Address,50,stdin);

    int m = strlen(u1.Address);
    int e; while ((e = getchar()) != '\n' && e != EOF) {}
    if(u1.Address[m-1] == '\n')
        u1.Address[m-1] = '\0';

    printf("Enter your Father's Name: ");
    fgets(u1.Father_Name,50,stdin);

    printf("Enter your Mother's Name: ");
    fgets(u1.Mother_Name,50,stdin);

    system("cls");

    int type;
    printf("Enter your Type of Account: ");
    printf("\n1. Saving\t2. Current\t3. Fixed\t4. NRI\n");
    scanf("%d", &type);

    if(type == 1)
        strcpy(u1.Type_account, "Saving");
    else if(type == 2)
        strcpy(u1.Type_account, "Current");
    else if(type == 3)
        strcpy(u1.Type_account, "Fixed");
    else if(type == 4)
        strcpy(u1.Type_account, "NRI");
    else{
        printf("Invalid Input");
        
        }

    printf("Enter your Password: ");
    for(int i = 0; i < 20; i++)
    {
        char ch = getch();
        if(ch != 13) //13 is the ASCII code for enter
        {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
        else
            break;
    }

    if(password[strlen(password) - 1] == '\n')
        password[strlen(password) - 1] = '\0';
    
    fwrite(&u1, sizeof(u1), 1, fp);
    fclose(fp);

    accountcreated();
}

void accountcreated()
{
    system("cls");
    printf("\nAccount Created Successfully");
    printf("\nPress Enter any key to Continue");
    getch();
    login();
}

void login(){
    char username[50];
    char password[20];

    FILE *fp, *fu;
    struct detailes u1;
    fp = fopen("username.txt", "rb");

    system("cls");

    if(fp == NULL){
        printf("Error! File not Found");
        exit(1);
    }

    int c; 
    while ((c = getchar()) != '\n' && c != EOF) {}
    printf("Enter your Username: ");

    fgets(username, 50, stdin);
    username[strcspn(username, "\n")] = 0;

    if (username[strlen(username) - 1] == '\n')
    {
        username[strlen(username) - 1] = '\0';
    }

    int d; 
    while ((d = getchar()) != '\n' && d != EOF) {}
    printf("\nEnter your Password: ");

    for(int i = 0; i < 20; i++)
    {
        char ch = getch();
        if(ch != 13) //13 is the ASCII code for enter
        {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
        else
            break;
    }

    if(password[strlen(password) - 1] == '\n')
        password[strlen(password) - 1] = '\0';



   // while(fread(&u1, sizeof(u1), 1, fp)){
        if((strcmp(username, u1.username) == 0)&&(strcmp(password, u1.password) == 0))
            {
                accountlogin(u1.username); //pass the username as argument
            }

            else{
                system("cls");
                printf("Credentials do not match");
                printf("\nPress Enter to Continue");
                getch();
                login();
            }
   // }

    fclose(fp);
}

void accountlogin(char username1[])
{
    FILE *fp;
    struct detailes u1;
    fp = fopen("username.txt", "rb");

    system("cls");//clears the screen
    printf("\nFetching Account Details...");
    Sleep(4000); //creating delay
    printf("\nLogin Successful");
    printf("\nPress Enter to Continue");
    getch();//waits for user to press enter

    display(username1);

}

void display(char username1[])
{
    system("cls");
    FILE *fp;
    struct detailes u1;
    fp = fopen("username.txt", "rb");

    if(fp == NULL)
    {
        printf("Error in Opening File");
        return ;
    }
        if(strcmp(username1, u1.username) == 0)
        {
            printf("Welcome, %s", u1.username);

            printf("Account INFO");
            printf("\nFather's Name: %s", u1.Father_Name);
            printf("\nMother's Name: %s", u1.Mother_Name);
            printf("\nAdhaar Number: %ld", u1.Adhaar_No);
            printf("\nPhone Number: %ld", u1.Phone_No);
            printf("\nAddress: %s", u1.Address);
            printf("\nType of Account: %s", u1.Type_account);
        }

    fclose(fp);
    int choice;

    printf("\nChoose your Action:");
    printf("1. Check Balance\n2. Transfer Money\n3. Logout\n4. Exit\n");
    scanf("%d", &choice);

    switch(choice){
        case 1: checkbalance(username1);
                break;
        case 2: transfer(username1);
                break;
        case 3: logout();
                break;
        case 4: exit(0);
                break;
        default: printf("Invalid Choice");
                break;
    }
}

void transfer(char username1[]){
    FILE *fp, *fm;
    struct detailes u1;
    struct detailes m1;
    char username[50];
    char usernamep[50];
    int i, j;
    system("cls");
    fp = fopen("username.txt", "rb");
    fm = fopen("mon.txt", "ab");

    printf("Transfer Money");
    printf("From (Your Username): ");
    scanf("%s", &username);

    printf("To (Username of Person): ");
    scanf("%s", &usernamep);

    while(fread(&u1, sizeof(u1), 1, fp)){
        if(strcmp(username, u1.username) == 0)
        {
            strcpy(m1.username, u1.username);
            strcpy(m1.password, u1.password);
        }
    }

    printf("Enter the Amount to Transfer: ");
    scanf("%ld", &m1.Amount);

    fwrite(&m1, sizeof(m1), 1, fm);

    system("cls");
    printf("Transfering Money");
    Sleep(4000);
    printf("\nAmount Successfully Transferred");
    getch();

    fclose(fp);
    fclose(fm);

    display(username1);
}

void checkbalance(char username2[]){
    FILE *fm;
    struct detailes m1;
    char ch;
    int i = 1, sum_money = 0;

    fm = fopen("mon.txt", "rb");

    int k = 5, l = 10;
    int m = 30, n = 10;
    int u = 60, v = 10;

    printf("Balance Dashboard");
    printf("S no.\tTransaction ID\tAmount");

    while(fread(&m1, sizeof(m1), 1, fm)){
        if(strcmp(username2, m1.username) == 0){
            printf("%d", i);
            i++;
            printf("%s", m1.username);
            printf("%ld", m1.Amount);
            sum_money = sum_money + m1.Amount;
        }
    }

    printf("Total Amount: %ld", sum_money);
    getch();
    fclose(fm);
    getch();
    display(username2);
}

void logout()
{

    system("cls");
    printf("Logging Out...");
    Sleep(4000);
    printf("Logged Out Successfully");
    printf("Press Enter to Continue");
    getch();
    account();
}

int main(){

    struct detailes user1;
    int choice;

    system("cls");

    printf("Welcome to Banking System");
    printf("\n1. Create Account\n2. Login\n3. Exit\n");
    scanf("%d", &choice);

    switch(choice){
        case 1: account();
                break;
        case 2: login();
                break;
        case 3: exit(0);
                break;
        default: printf("Invalid Choice");
                break;
    }
    return 0;
}

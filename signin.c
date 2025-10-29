#include<stdio.h>

void signinpathway()
{
   char first[100] , middle[100] , last[100];
   int hasMiddle;
    printf("\nEnter your first name:");
    scanf("%s",first);

     printf("\nDo you have a middle name? (1 = Yes, 2 = No): ");
    scanf("%d", &hasMiddle);

    if (hasMiddle == 1)
    {
        printf("Enter your middle name: ");
        scanf("%s", middle);
    }
    else
    {
        middle[0] = '\0';  // make middle name empty
    }

    printf("\nEnter your last name:");
    scanf("%s",last);

    printf("\nYour full name is %s %s %s.",first, middle, last);

}


void signoutpathway()
{
    printf("Thankyou so much for visiting our website.");
    
}
void getPhoneNumber()
{
    long long number; // to hold 10-digit number
    int isValid = 0;

    while (!isValid)
    {
        printf("\nEnter your phone number (10 digits): ");
        scanf("%lld", &number);

        if (number >= 1000000000 && number <= 9999999999)
        {
            printf("\nPhone number accepted: %lld\n", number);
            isValid = 1;
        }
        else
        {
            printf("❌Invalid phone number! Please enter exactly 10 digits.\n");
        }
    }
}

int main()
{
    long long number;
    int signout;
    int choice;
    int isValid = 0;

    printf("\n\t *************** BUS RESERVATION SYSTEM ***************");

    printf("\n\n-----MENU-----\n");

    printf("\n 1. Login \n 2.Exit\n");
    printf("\nEnter your choice :");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        
    signinpathway();

    printf("\n\n1. Yes \n2. No \nEnter your choice :");
    scanf("%d",&choice);


    if(choice==1)

    {
        getPhoneNumber();

        printf("\n\t------------You are successfully signedin------------\n"); 
        break;

    }
   
    
    else
    {
      do
      {
        printf("\nEnter your choice : \n1. Do you want to re-enter  your details \n2. Exit\n");
        printf("\nEnter your choice :");
        scanf("%d",&choice);

        if(choice==1)
        {
          signinpathway();

        }
        
        else
        {
            break;
        }
        
      }while(choice==1);
       getPhoneNumber();

        printf("\n\t------------You are successfully signedin------------\n");
        break;
    }
       
        
       
    case 2:
        signoutpathway();
        break;
    
    default:printf("Please enter a valid choice");
        break;
    }
}
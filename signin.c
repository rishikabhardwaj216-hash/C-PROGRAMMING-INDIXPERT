#include <stdio.h>


int busNumber[25];
int seats[25];
int totalBookings = 0;



void signinpathway()
{
    char first[100], middle[100], last[100];
    int hasMiddle;

    printf("\nEnter your first name: ");
    scanf("%s", first);

    printf("\nDo you have a middle name? (1 = Yes, 2 = No): ");
    scanf("%d", &hasMiddle);

    if (hasMiddle == 1)
    {
        printf("Enter your middle name: ");
        scanf("%s", middle);
    }
    else
    {
        middle[0] = '\0'; 
    }

    printf("\nEnter your last name: ");
    scanf("%s", last);

    printf("\nYour full name is %s %s %s.\n", first, middle, last);
}

void busmenu()
{
    printf("\n\t *==*==** User Menu **==*==*\n");
    printf("\n1. Book a ticket\n2. Cancel a ticket\n3. Check bus status\n4. Logout\n");
}

void bookBus()
{
    int num;

    printf("\nHow many buses do you want to book (max 25)? ");
    scanf("%d", &num);

    if (num <= 0 || num > 25)
    {
        printf("Invalid number of bookings.\n");
        return;
    }

    for (int i = 0; i < num; i++)
    {
        if (totalBookings >= 25)
        {
            printf("\nBooking limit reached! Cannot book more.\n");
            return;
        }

        printf("\nEnter bus number for booking %d: ", totalBookings + 1);
        scanf("%d", &busNumber[totalBookings]);

        printf("Enter number of seats to book for Bus %d: ", busNumber[totalBookings]);
        scanf("%d", &seats[totalBookings]);

        printf("Bus %d booked with %d seats.\n", busNumber[totalBookings], seats[totalBookings]);

        totalBookings++;
    }
}

void cancelTicket()
{
    int cancelBus;
    int found = 0;

    if (totalBookings == 0)
    {
        printf("\nNo bookings available to cancel.\n");
        return;
    }

    printf("\nEnter bus number you want to cancel: ");
    scanf("%d", &cancelBus);

    for (int i = 0; i < totalBookings; i++)
    {
        if (busNumber[i] == cancelBus)
        {
            found = 1;
            printf("\nBooking for Bus %d (%d seat(s)) cancelled successfully.\n", busNumber[i], seats[i]);

           
            for (int j = i; j < totalBookings - 1; j++)
            {
                busNumber[j] = busNumber[j + 1];
                seats[j] = seats[j + 1];
            }

            totalBookings--;
            break;
        }
    }

    if (!found)
    {
        printf("No booking found for Bus %d.\n", cancelBus);
    }
}

void showBusStatus()
{
    if (totalBookings == 0)
    {
        printf("\nNo active bookings found.\n");
        return;
    }

    printf("\nCurrent Bus Bookings:\n");
    printf("-----------------------------------\n");
    printf("Bus No.\tSeats Booked\n");
    printf("-----------------------------------\n");

    for (int i = 0; i < totalBookings; i++)
    {
        printf("%d\t%d\n", busNumber[i], seats[i]);
    }
    printf("===================================\n");
}

void signoutpathway()
{
    printf("Thank you so much for visiting our reservation system.\n");

    signinpathway();
}

void getPhoneNumber()
{
    long long number; 
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
            printf("Invalid phone number! Please enter exactly 10 digits.\n");
        }
    }
}

int main()
{
    int choice;

    printf("\n\t *************** BUS RESERVATION SYSTEM ***************\n");

    printf("\n-----MENU-----\n");
    printf("1. Login\n2. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        signinpathway();

        printf("\n\n1. Yes \n2. No \nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            getPhoneNumber();

            printf("\n\t------------You are successfully signed in------------\n");

            do
            {
                busmenu();
                printf("\nEnter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    bookBus();
                    break;
                case 2:
                    cancelTicket();
                    break;
                case 3:
                    showBusStatus();
                    break;
                case 4:
                    signoutpathway();
                    break;
                default:
                    printf("Invalid choice! Try again.\n");
                    break;
                }
            } while (choice != 4);
        }
        else
        {
            do
            {
                printf("\nEnter your choice:\n1. Re-enter your details\n2. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    signinpathway();
                }
                else
                {
                    break;
                }

            } while (choice == 1);

            getPhoneNumber();

            printf("\n\t------------You are successfully signed in------------\n");

            do
            {
                busmenu();
                printf("\nEnter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    bookBus();
                    break;
                case 2:
                    cancelTicket();
                    break;
                case 3:
                    showBusStatus();
                    break;
                case 4:
                    signoutpathway();
                    break;
                default:
                    printf("Invalid choice! Try again.\n");
                    break;
                }
            } while (choice != 4);
        }
        break;

    case 2:
        signoutpathway();
        break;

    default:
        printf("Please enter a valid choice.\n");
        break;
    }

    return 0;
}

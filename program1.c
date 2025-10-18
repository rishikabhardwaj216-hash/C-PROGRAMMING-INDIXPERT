#include<stdio.h>

int deletenumber(int number[],int n)
{
  if(n==0)
  {
      printf("Sorry!No number is left to delete.");
      return n;
  }
  else
  {
      printf("The last number you have entered %d is deleted successfully.",number[n-1]);
       if(n>0)
        n--;
      return n;
  }
}
void show(int number[],int n)
{
   if(n==0)
   {
       printf("Oops! No number is left to show here.");
   }
   
   else
   {
       printf("\nYou updated entries are:");
        for (int i = 0; i < n; i++)
        {
            printf(" %d", number[i]);
        }
        printf("\n");
   }
}
int insertprogram(int number[],int n)

{
    if (n >= 5)
    {
        printf("Sorry! Array is full. Cannot insert more numbers.\n");
        return n; 
    }
     else
    {
        printf("\nEnter new number: ");
        scanf("%d", &number[n]);
        n++; 
        printf("\nNumber %d inserted successfully.\n",number[n-1]);
        return n; 
    }
}


void exitprogram()
{
  
    printf("----------You have exited successfully----------");
}

int main()
{
    int choice;
    int number[5];
    int n=5;

    printf("Enter any 5 numbers accouding to your choice.\n");
    
    for(int i=0;i<5;i++)
    {

        printf("Enter your %d number:",i+1);
        scanf("%d",&number[i]);
    }
    
    printf("You have entered:");
    for(int i=0;i<5;i++)
    {
        printf(" , %d",number[i]);
    } 
    
    while(1)
    
  {
    printf("\n\nMark your chooice:\n");
    
    printf("\n 1. Delete a number.\n 2. View numbers \n 3. Insert a new choice\n 4. Exit");
    
    printf("\n\nEnter your choice here:");
    scanf("%d",&choice);
    if(choice==1)
    {
        n = deletenumber(number, n);
        
    }
    else if(choice==2)
    {
        show(number,n);
    }
    
    
    
    else if(choice==3)
    {
        n = insertprogram(number, n);
        
    }
    
    
    else if(choice==4)
    {
      exitprogram();
      break;
    } 
    
    else
    {
        printf("\nInvalid choice. Please try again and insert a valid choice(i.e. 1,2,3).");
    }

  }
    return 0;
  
  
}

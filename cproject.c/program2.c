#include<stdio.h>
#include<string.h>

char greet()
{
    printf("\n\t****************");

    printf("\n\tHellow!\n");

    printf("\t****************");

    printf("\nPlease enter your full name and then i'll tell you that how many vowels are there in your name.");
    
    return 0;
}


int main()
{
   greet();
   char name[50];
   char ch; 
   
   int acount = 0, ecount = 0, icount = 0, ocount = 0, ucount = 0;

    printf("\n\n\nEnter your name:");
    scanf("%[^\n]",name);
     

    for (int i = 0; i <strlen(name); i++)
    {
        char ch = name[i];
        
        if (ch == 'A' || ch == 'a')
            acount++;

        else if (ch == 'E' || ch == 'e')
            ecount++;

        else if (ch == 'I' || ch == 'i')
            icount++;

        else if (ch == 'O' || ch == 'o')
            ocount++;

        else if (ch == 'U' || ch == 'u')
            ucount++;
    }

    printf("A/a = %d\n", acount);
    printf("E/e = %d\n", ecount);
    printf("I/i = %d\n", icount);
    printf("O/o = %d\n", ocount);
    printf("U/u = %d\n", ucount);
        
    printf("\n\n The total number of times you have repeated the vowel A/a is %d", acount);

    printf("\n The total number of times you have repeated the vowel E/e is %d", ecount);

    printf("\n The total number of times you have repeated the vowel I/i is %d", icount);

    printf("\n The total number of times you have repeated the vowel O/o is %d", ocount);

    printf("\n The total number of times you have repeated the vowel U/u is %d", ucount);
   
    


    return 0;
}
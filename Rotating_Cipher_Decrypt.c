#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/* custom function prototype with arguments two data type.
    1. encrypted character
    2. key/shift amount integer
*/
void decrypt(char*encrypted, int x);//custom function prototype

int main()
{
    //Declaring Variables
    char input[300];
    int shift;


    //Input from user (multi-word string)
    printf("\nEnter message to be decrypted: ");
    scanf("%[^\n]s",&input);//
    printf("\nEnter shift (1-25): ");
    scanf("%d",&shift);

    if (shift < 1 || shift > 25) //Checking if user input is inbetween 1 and 25, if not end program with error message.
    {
        printf("Error, Enter number between 1 and 25.");
        return 0;
    }

    decrypt(input, shift);//Calling the custom function

    printf("\nDecrypted message: %s \n\nPress any key to exit.",input);//Printing input as encrpyted.
    getch();//preventing the program from quitting without user permission.
}

void decrypt(char *encrypted, int x)// defining the custom function.
{
    char letters;
    int i;

    for (i = 0; i < strlen(encrypted); i++)//Checking each letters of the input whether its capital or lowercase letters
    {
        letters = encrypted[i];
        if (letters >= 'A' && letters <= 'Z')
        {
            //the key for decryption is d(c)=(c-k)%26
            letters = ((letters-'A')+x)%26;
            letters += 'A';
            encrypted[i] = letters;
        }
        else if (letters >= 'a' && letters <= 'z')
        {
            letters = ((letters-'a')+x)%26;
            letters += 'a';
            encrypted[i] = letters;
        }
    }
}

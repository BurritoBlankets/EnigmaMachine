/************************************************************
*
*  File: RotorPath.c
*  Author:  Jake Klinger, Jose (Pillo) Duenas-Lopez, Tyler Bruno
*  Version: 0.10 (Mar 22, 2023)
*
*  Purpose:
*            Implement multidimensional array for each rotor and reflector
*            and have the rotors change positions with each character in the
*            input message.
*
*  Note: When compiling use - std=c99
*
*        "MESSY CODE THAT WORKS"
*************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>


// Multidimensional array for the three rotors and reflector
char *RotorPath[4][26] = {
        {"F", "A", "C", "X", "V", "R", "M", "S", "U", "O", "Y", "T", "N", "I", "H", "D", "L", "E", "G", "W", "J", "K", "P", "Q", "Z", "B"},  //Rotor 3
        {"K", "C", "L", "Q", "M", "S", "W", "H", "T", "J", "D", "N", "V", "O", "U", "X", "P", "G", "F", "A", "B", "E", "Y", "R", "Z", "I"},  //Rotor 2
        {"K", "T", "N", "O", "R", "G", "Q", "L", "F", "D", "V", "P", "X", "W", "C", "E", "I", "Y", "M", "U", "Z", "S", "J", "A", "H", "B"},  //Rotor 1
        {"I", "L", "W", "Z", "F", "E", "S", "X", "A", "O", "U", "B", "R", "Y", "J", "V", "T", "M", "G", "Q", "K", "P", "C", "H", "N", "D"}}; // Reflector

void string_formatter(char *message)
{
    int new_total_index = 0;
    //var used to reformat string array, whatever value assigned after the for
    //loop will be the new total number of indices in the string array


    //Removes non-alphabet characters from string
    for(int i = 0; message[i] != '\0'; i++)
    {
        if (0 != isalpha(message[i]))
        {
            message[new_total_index] = message[i];
            new_total_index++;
        }
    }
    message[new_total_index] = '\0';
    //appends null character to end of reformated string

    //Makes all letters uppercase
    for(int i = 0; message[i] != '\0'; i++)
    {
        if (0 == isdigit(message[i]))
        {
            message[i]=toupper(message[i]);
        }
    }
}

void PrintRotor(int j) // Prints what Current Rotor is.
{
    for (int i = 0; i < 26; i++)
            printf("%s", RotorPath[j][i]);
}

void Rotor3Spin() // Spins Rotor 1 once
{
    char *store;
    store = RotorPath[0][25];
        for (int i = 25; i > 0; i--)
        {
            RotorPath[0][i] = RotorPath[0][i-1];
        }
    RotorPath[0][0] = store;
}
void Rotor2Spin() // Spins Rotor 2 once
{
    char *store;
    store = RotorPath[1][25];
        for (int i = 25; i > 0; i--)
        {
            RotorPath[1][i] = RotorPath[1][i-1];
        }
    RotorPath[1][0] = store;
}
void Rotor1Spin() // Spins Rotor 3 once
{
    char *store;
    store = RotorPath[2][25];
        for (int i = 25; i > 0; i--)
        {
            RotorPath[2][i] = RotorPath[2][i-1];
        }
    RotorPath[2][0] = store;
}

void SetRotors(int R1,int R2,int R3) // Takes user input and spins the rotors to the correct amount of times before the message is recieved
{
    for(int i = 0; i < R1 ; i++)
    {
        Rotor1Spin();
    }
    printf("*******************************\n");

    for (int i = 0; i < R2 ; i++)
    {
        Rotor2Spin();
    }
    printf("------------------------------\n");

    for (int i = 0; i < R3 ; i++)
    {
        Rotor3Spin();
    }
}

void CharacterEncryption(int input) //Function to send a character through the rotors and back and receive decrypted character
{
    int temp;
    temp = input;
    for (int i = 0; i <= 3; i++)
    {
        temp = * RotorPath[i][temp] - 65;

    }

    for (int j = 2; j >= 0; j--)
    {
        for(int i = 0; i < 26; i++)
        {
            if(* RotorPath[j][i] - 65 == temp )
            {
                temp = i;
                break;
            }
        }

    }

    FILE* file=fopen("EnigmaTranscript.txt","a");
    printf("%c", temp + 65);
    fprintf(file, "%c", temp + 65);

}

void MessageEncryption()
{
}

int main()
{

    FILE* file=fopen("EnigmaTranscript.txt","a");
    int Message_Length, R3_Change, R2_Change, R1_Change;
    // Setting Rotors
    char R1, R2, R3, Message[1000], temp, RotorPointer[3];
    //Rotor positions (1-3), User Message Var, temporary value which aids in reading user input


    fprintf(file, "\n");
    for( int i = 0; i <= 2; i++ )
    {
        printf("Set rotor %d position (A-Z): ",i+1);
        fscanf(stdin, " %c",&RotorPointer[i]);
        string_formatter(&RotorPointer[i]);
        fprintf(file, "ROTOR %d: %c\n", i+1, RotorPointer[i]);
    }
    R1=RotorPointer[0];
    R2=RotorPointer[1];
    R3=RotorPointer[2];


    printf("MESSAGE: ");

    scanf("%c",&temp); // temp statement to clear buffer
    fgets(Message, 1000, stdin);
    string_formatter(Message);
    fprintf(file, "UNENCRYPTED:\n%s\n", Message);

    fprintf(file, "ENCRYPTED:\n\n");


//////////////////////MESSAGE ENCTYPTOR////////////////////////////////
    Message_Length = 0;
    for(int i = 0; Message[i] != '\0'; i++)
    {
        Message_Length++;
    }
    R1_Change = Message_Length/676;
    R2_Change = Message_Length/26;
    if (Message_Length > 26)
        R3_Change = 25;
    else
        R3_Change = Message_Length;

    // Runs if Message is long enough the first rotor spins (more than 676 characters)
   if (R1_Change > 0)
   {
       for(int k = 0; k < R1_Change ; k++)
       {
           for (int j = 0; j < R2_Change ; j++)
           {
               for (int i = 0; i < R3_Change; i++)
               {
                   CharacterEncryption(Message[i]-65);
                   Rotor3Spin();
               }
               Rotor2Spin();

           }
           Rotor1Spin();

       }
   }
   // Runs if Message is long enough the second rotor spins (more than 26 characters)
   if (R2_Change > 0)
   {
       for (int j = 0; j < R2_Change ; j++)
       {
           for (int i = 0; i < R3_Change; i++)
           {
                CharacterEncryption(Message[i]-65);
                Rotor3Spin();
           }
           Rotor2Spin();

       }
   }
   // Runs if Message is smaller than 26 characters.
   if (R3_Change < 26)
   {
       for (int i = 0; i < R3_Change; i++)
       {
           CharacterEncryption(Message[i]-65);
           Rotor3Spin();
       }
   }
   printf("\n");
  return 0;
}

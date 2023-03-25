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
*************************************************************/

#include <stdio.h>
#include <string.h>

// Multidimensional array for the three rotors and reflector
char *RotorPath[4][26] = {
        {"F", "A", "C", "X", "V", "R", "M", "S", "U", "O", "Y", "T", "N", "I", "H", "D", "L", "E", "G", "W", "J", "K", "P", "Q", "Z", "B"},  //Rotor 3
        {"K", "C", "L", "Q", "M", "S", "W", "H", "T", "J", "D", "N", "V", "O", "U", "X", "P", "G", "F", "A", "B", "E", "Y", "R", "Z", "I"},  //Rotor 2
        {"K", "T", "N", "O", "R", "G", "Q", "L", "F", "D", "V", "P", "X", "W", "C", "E", "I", "Y", "M", "U", "Z", "S", "J", "A", "H", "B"},  //Rotor 1
        {"I", "L", "W", "Z", "F", "E", "S", "X", "A", "O", "U", "B", "R", "Y", "J", "V", "T", "M", "G", "Q", "K", "P", "C", "H", "N", "D"}}; // Reflector

void PrintRotor(int j) // Prints what Current Rotor is.
{
    for (int i = 0; i < 26; i++)
            printf("%s", RotorPath[j][i]);
            printf("\n");
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
void Rotor2Spin() // Spins Rotor 3 once
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

int main() 
{
   
    int Message_Length, R3_Change, R2_Change, R1_Change;
    // Setting Rotors
    char R1,R2,R3;
    printf("Set rotor positions (A-Z): ");
    scanf(" %c",&R1);
    scanf(" %c",&R2);
    scanf(" %c",&R3);
    SetRotors(R1-65,R2-65,R3-65);
    
    
    // Finds length of message
    char Message[1000];
    printf("Message: ");
    scanf("%s" , &Message);
    Message_Length = strlen(Message);
    
    // Values to check how many times the upper rotors spin
    R1_Change = Message_Length/676;
    R2_Change = Message_Length/26;
    if (Message_Length > 26)
        R3_Change = 25;
    else 
        R3_Change = Message_Length;
   
   // Runs if Message is long enough the first rotor spins (more than 676 characters)
   if (R1_Change > 0)
   {
       for(int k = 0; k< R1_Change ; k++) 
       {
           for (int j = 0; j < R2_Change ; j++)
           {
               for (int i = 0; i < R3_Change; i++)
               {
                   Rotor3Spin();
               }
               Rotor2Spin();
               printf("------------------------------\n");
           }
           Rotor1Spin();
           printf("*******************************\n");
       }
   }
   // Runs if Message is long enough the second rotor spins (more than 26 characters)
   if (R2_Change > 0); 
   {
       for (int j = 0; j < R2_Change ; j++)
       {
           for (int i = 0; i <= R3_Change; i++)
           {
                Rotor3Spin();
           }
           Rotor2Spin();
           printf("------------------------------\n");
       }
   }
   // Runs if Message is smaller than 26 characters.
   if (R3_Change < 26)
   {
       for (int i = 0; i < R3_Change; i++)
       {
           Rotor3Spin();
       }
   }
   
   
  return 0;
}
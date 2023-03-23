/************************************************************
*
*  File: RotorPath.c
*  Author:  Jake Klinger, Jose (Pillo) Duenas-Lopez, Tyler Bruno
*  Version: 0.10 (Mar 22, 2023)
*  
*  Purpose: 
*            Implement multidimensional array for each rotor and reflector 
*            and have the rotors change positions with each charactor in the 
*            input message.
*
*  To-Do:
*            Spin rotor after each character and every 26th turn rotor 2 turns
*            and rotor 1 turns every 676 turns
*
*************************************************************/

#include <stdio.h>
#include <string.h>

char *RotorPath[4][26] = {
        {"K", "T", "N", "O", "R", "G", "Q", "L", "F", "D", "V", "P", "X", "W", "C", "E", "I", "Y", "M", "U", "Z", "S", "J", "A", "H", "B"},
        {"K", "C", "L", "Q", "M", "S", "W", "H", "T", "J", "D", "N", "V", "O", "U", "X", "P", "G", "F", "A", "B", "E", "Y", "R", "Z", "I"},
        {"F", "A", "C", "X", "V", "R", "M", "S", "U", "O", "Y", "T", "N", "I", "H", "D", "L", "E", "G", "W", "J", "K", "P", "Q", "Z", "B"},
        {"I", "L", "W", "Z", "E", "C", "S", "X", "D", "O", "J", "H", "A", "F", "G", "V", "T", "M", "N", "K", "B", "P", "Q", "U", "Y", "R"}};
        // Multidimensional array for the three rotors and reflector

void Rotor1Spin() // Spins Rotor 1 once
{
    char *store;
    int X = 0;    
    store = RotorPath[0][25];
        for (X = 25; X > 0; X--)
        {
            RotorPath[0][X] = RotorPath[0][X-1];
        }
    RotorPath[0][0] = store;
    
    for (X = 0; X < 26; X++)
        printf("%s", RotorPath[0][X]);
        printf("\n");
}
void Rotor2Spin() // Spins Rotor 2 once
{
    char *store;
    int X = 0;    
    store = RotorPath[1][25];
        for (X = 25; X > 0; X--)
        {
            RotorPath[1][X] = RotorPath[1][X-1];
        }
    RotorPath[1][0] = store;
    
    for (X = 0; X < 26; X++)
        printf("%s", RotorPath[1][X]);
        printf("\n");
}
void Rotor3Spin() // Spins Rotor 3 once
{
    char *store;
    int X = 0;    
    store = RotorPath[2][25];
        for (X = 25; X > 0; X--)
        {
            RotorPath[2][X] = RotorPath[2][X-1];
        }
    RotorPath[2][0] = store;
    
    for (X = 0; X < 26; X++)
        printf("%s", RotorPath[2][X]);
        printf("\n");
}

void SetRotors(int R1,int R2,int R3)
{
    int X = 0,Y = 0, Z = 0;
    for(Z = 0; Z< R1 ; Z++) 
        Rotor1Spin();
    printf("*******************************\n");
    for (Y = 0; Y < R2 ; Y++)
               Rotor2Spin();
    printf("------------------------------\n");
    for (X = 0; X < R3; X++)
                   Rotor3Spin();
   // Takes user input and spins the rotors to the correct amount of times before the message is recieved

} 
 
int main() 
{
   
    int X = 0,Y = 0, Z = 0, Message_Length;
    
    char R1,R2,R3;
    scanf(" %c",&R1);
    scanf(" %c",&R2);
    scanf(" %c",&R3);
    SetRotors(R1-65,R2-65,R3-65);
    
    // Setting Rotors
    
    char Message[1000];
    
    printf("Message: ");
    scanf("%s" , &Message);
    
    Message_Length = strlen(Message);
    // Finds length of message
    
    int R3_Change;
    if (Message_Length > 26)
        R3_Change = 25;
    else 
        R3_Change = Message_Length;
    int R2_Change = Message_Length/26;
    int R1_Change = Message_Length/676;
    // Values to check how many times the upper rotors spin
   
   
   if (R1_Change > 0)
   {
       for(Z = 0; Z< R1_Change ; Z++) 
       {
           for (Y = 0; Y < R2_Change ; Y++)
           {
               for (X = 0; X < R3_Change; X++)
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
   // Runs if Message is long enough the first rotor spins (more than 676 characters)
   
   if (R2_Change > 0); 
   {
       for (Y = 0; Y < R2_Change ; Y++)
       {
           for (X = 0; X <= R3_Change; X++)
           {
                Rotor3Spin();
           }
           Rotor2Spin();
           printf("------------------------------\n");
       }
   }
   // Runs if Message is long enough the second rotor spins (more than 26 characters)
   if (R3_Change < 26)
   {
       for (X = 0; X < R3_Change; X++)
       {
           Rotor3Spin();
       }
   }
   // Runs if Message is smaller than 26 characters.
   
  return 0;
}

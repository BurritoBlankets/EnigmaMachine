/************************************************************
*
*  File: MessageEncryption.h
*  Author:  Jake Klinger, Jose (Pillo) Duenas-Lopez, Tyler Bruno
*  Version: 0.90(Mar 26, 2023)
*  
* Purpose: 
*            Contains the function to encrypt and decrypt messages. 
*
*
*************************************************************/


#include <stdio.h>
#include <string.h>
#include "RotorMovement.h"
#include "RotorWiring.h"

void CharacterEncryption(int Character) //Function to send a character through the rotors and back and receive decrypted character
{
    int temp;
    temp = Character;
    for (int i = 0; i <= 3; i++)
    {
        temp = * RotorPath[i][temp] - 65;
        printf("%d\n",temp);
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
        printf("%d\n",temp);
    }
    printf("%c\n", temp + 65); 
}

void MessageEncryption()
{

    int Message_Length, R3_Change, R2_Change, R1_Change;
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
   if (R2_Change > 0); 
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
}


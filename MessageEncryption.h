/************************************************************
*
*  File: MessageEncryption.h
*  Author:  Jake Klinger, Jose (Pillo) Duenas-Lopez, Tyler Bruno
*  Version: 1.0(Mar 28, 2023)
*  
* Purpose: 
*            Contains the function to encrypt and decrypt messages. 
*
*
*************************************************************/

#pragma once
#include <stdio.h>
#include <string.h>
#include "RotorMovement.h"

char CharacterEncryption(int input) //Function to send a character through the rotors and back and receive decrypted character
{
    // Character -> 3 -> 2 -> 1 -> Reflector -> 1 -> 2 -> 3 -> Encrypted Character
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
    temp = temp + 65;
    return temp;
}

char MessageEncryption(char *Message, char R3,  char R2)
{
    FILE* file=fopen("EnigmaTranscript.txt","a");
    int Message_Length = 0, CountR3 = R3 - 65 , CountR2 = R2 - 65;
    char EncryptedMessage[1000];
    // Finds Length of the input message
    for(int i = 0; Message[i] != '\0'; i++)
    {
        Message_Length++;
    }
    //Encrypts or Decrypts the message the user input
    for(int i = 0; i < Message_Length; i++)
    {
        EncryptedMessage[i] = CharacterEncryption(Message[i] - 65);
        printf("%c", EncryptedMessage[i]);
        fprintf(file, "%c", EncryptedMessage[i]);
        Rotor3Spin();
        CountR3++;
        if (CountR3 == 26) // Spins second Rotor 2 onece Rotor 3 gets to A
        {
            CountR3 = 0;
            Rotor2Spin();
            CountR2 ++;
        }
        if (CountR2 == 26) // Spins second Rotor 1 once Rotor 2 gets to A
        {
            CountR2 = 0;
            Rotor1Spin();
        }
    }
    fprintf(file, "\n");
    fclose(file);
    printf("\n");
}

char CharacterEncryptionSteps(int input) //Function to return step by step encryption
{

    // Character -> 3 -> 2 -> 1 -> Reflector -> 1 -> 2 -> 3 -> Encrypted Character
    int temp;
    temp = input;
    for (int i = 0; i <= 3; i++) 
    {
        printf("%c -> " , temp + 65);
        temp = * RotorPath[i][temp] - 65; 
    }

    for (int j = 2; j >= 0; j--)
    {
        for(int i = 0; i < 26; i++)
        {
            if(* RotorPath[j][i] - 65 == temp )
            {
                temp = i;
                printf("%c -> " , temp + 65);
                break;
            }
        }
    }
    printf("Output is: [%c] ", temp +65);
    temp = temp + 65;
    return temp;
}

void MessageEncryptionSteps(char *Message, char R3,  char R2, char R1) // Coupled with step by step encryption
{
    FILE* file=fopen("EnigmaTranscript.txt","a");
    int Message_Length = 0, CountR3 = R3 - 65 , CountR2 = R2 - 65, CountR1 = R1 - 65;
    char EncryptedMessage[1000];
    // Finds Length of the input message
    for(int i = 0; Message[i] != '\0'; i++)
    {
        Message_Length++;
    }
    //Encrypts or Decrypts the message the user input
    for(int i = 0; i < Message_Length; i++)
    {
        EncryptedMessage[i] = CharacterEncryptionSteps(Message[i] - 65);
        printf("at rotor positons [%c%c%c]\n", CountR1 + 65, CountR2 + 65, CountR3 + 65);
        fprintf(file, "%c", EncryptedMessage[i]);
        Rotor3Spin();
        CountR3++;
        if (CountR3 == 26) // Spins second Rotor 2 onece Rotor 3 gets to A
        {
            CountR3 = 0;
            Rotor2Spin();
            CountR2 ++;
        }
        if (CountR2 == 26) // Spins second Rotor 1 once Rotor 2 gets to A
        {
            CountR2 = 0;
            Rotor1Spin();
            CountR1++;
        }
        if (CountR1 == 26) // Spins second Rotor 1 once Rotor 2 gets to A
        {
            CountR1= 0;
        }
    }
    fclose(file);
    printf("\n");
}

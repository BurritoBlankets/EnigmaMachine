/************************************************************
*
*  File: MessageEncryption.h
*  Author:  Jake Klinger, Jose (Pillo) Duenas-Lopez, Tyler Bruno
*  Version: 0.20(Mar 24, 2023)
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

void CharacterEncryption(int input) //Function to send a character through the rotors and back and receive decrypted character
{
    char encrypted_message_string[1000];
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

}

void MessageEncryption(char *Message)
{
    int Message_Length = 0, Count1 = 0, Count2 = 0;
    // Finds Length of the input message
    for(int i = 0; Message[i] != '\0'; i++)
    {
        Message_Length++;
    }
    //Encrypts or Decrypts the message the user input
    for(int i = 0; i < Message_Length; i++)
    {
        CharacterEncryption(Message[i] - 65);
        Rotor3Spin();
        Count1++;
        if (Count1 == 26)
        {
            Count1 = 0;
            Rotor2Spin();
            Count2 ++;
        }
        if (Count2 == 26)
        {
            Count2 = 0;
            Rotor1Spin();
        }
    }
    printf("\n");
}

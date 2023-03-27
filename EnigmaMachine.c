/************************************************************
*  Most Complete Version DO NOT edit to test things, make a copy
*
*  File: EnigmaMachine.c
*  Author:  Jake Klinger, Jose (Pillo) Duenas-Lopez, Tyler Bruno
*  Version: 0.50 (Mar 27, 2023)
*
*  Purpose:
*            Take A message and encrypt the message so that you can enter 
*            that same encrypted message you received can dycrypt your message.
*            Makes use of three hardwired rotors to encrypt and decrypt messages
*            and at the same time the same input will not be the same output.
*  
*        
* References:
*          How The Enigma Works:
*          °https://www.101computing.net/enigma/enigma-instructions.html
*          °https://www.theguardian.com/technology/2014/nov/14/how-did-enigma-machine-work-imitation-game
*          °https://www.101computing.net/enigma-machine-emulator/
*          °https://hackaday.com/2017/08/22/the-enigma-enigma-how-the-enigma-machine-worked/
*          
*
*          Code Help:
*          °https://www.educative.io/answers/how-to-remove-spaces-from-a-string-in-c
*          °https://codeforwin.org/c-programming/c-program-to-search-element-in-array
*      
*          Custom Rotor Wiring Sheet:
*          °https://docs.google.com/spreadsheets/d/e/2PACX-1vRmON5SRXPrnoQghaJSrhbBFFNYLnJjPQOt1hKbfr99q6gwbxfU4B8qUEQg2Z-3A3x3OpXpFWCoSvqL/pubhtml
*
*
*  Note: When compiling use - std=c99
*************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "MessageEncryption.h"



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

int main()
{

    FILE* file=fopen("EnigmaTranscript.txt","a");
    int Message_Length;
    char Message[1000], temp, RotorPointer[3];
    //Rotor positions (1-3), User Message Var, temporary value which aids in reading user input


    fprintf(file, "\n");
    for( int i = 0; i <= 2; i++ )
    {
        printf("Set rotor %d position (A-Z): ",i+1);
        fscanf(stdin, " %c",&RotorPointer[i]);
        string_formatter(&RotorPointer[i]);
        fprintf(file, "ROTOR %d: %c\n", i+1, RotorPointer[i]);
    }
    // Sets Rotors at the begining
    SetRotors(RotorPointer[0], RotorPointer[1], RotorPointer[2]);

    // User Inputs Message:
    printf("MESSAGE: ");

    scanf("%c",&temp); // temp statement to clear buffer
    fgets(Message, 1000, stdin);
    string_formatter(Message);
    fprintf(file, "UNENCRYPTED:\n%s\n", Message);

    fprintf(file, "ENCRYPTED:\n\n");
    MessageEncryption(Message);

  return 0;
}

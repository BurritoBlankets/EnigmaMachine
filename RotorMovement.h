/************************************************************
*
*  File: RotorMovement.g
*  Author:  Jake Klinger, Jose (Pillo) Duenas-Lopez, Tyler Bruno
*  Version: 0.90 (Mar 25, 2023)
*  
*  Purpose: 
*            A file of multiple functions that will store the rotor order and
*            various functions that will be used frequently in main file.
*             
*************************************************************/

#include <stdio.h>
#include <string.h>
#include "RotorWiring.h"

void PrintRotor(int j) // Prints what Current Rotor is.
{
    for (int i = 0; i < 26; i++)
            printf("%s", RotorPath[j][i]);
            printf("\n");
}

void Rotor1Spin() // Spins Rotor 1 once
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
void Rotor3Spin() // Spins Rotor 3 once
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
    
    for (int i = 0; i < R2 ; i++)
    {
        Rotor2Spin();
    }
    
    for (int i = 0; i < R3 ; i++)
    {
        Rotor3Spin();
    }     
} 
 

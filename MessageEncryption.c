/************************************************************
*
*  File: MessageEncryption.c
*  Author:  Jake Klinger, Jose (Pillo) Duenas-Lopez, Tyler Bruno
*  Version: 0.20(Mar 24, 2023)
*  
* 0Purpose: 
*            Use multidimensional array to send a character through each rotor and back
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
        

void CharacterEncryption(int input) //Function to send a character through the rotors and back and receive decrypted character
{
    int temp;
    temp = input;
    for (int i = 0; i <= 3; i++)
    {
        temp = * RotorPath[i][temp] - 65;
        //printf("%d\n", temp);
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
        //printf("%d\n", temp);    
    }
    printf("%c\n", temp + 65);
        
    
}

int main() 
{
    CharacterEncryption(0);
    return 0;
}


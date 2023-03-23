/************************************************************
*
*  File: MessageEncryption.c
*  Author:  Jake Klinger, Jose (Pillo) Duenas-Lopez, Tyler Bruno
*  Version: 0.10 (Mar 23, 2023)
*  
*  Purpose: 
*            Use multidimensional array to send a character through each rotor and back
*            
*
*  To-Do:
*            Send a character through the matrix and come out with corosponding character
*
*************************************************************/


#include <stdio.h>
#include <string.h>

char *RotorPath[4][26] = {
        {"K", "T", "N", "O", "R", "G", "Q", "L", "F", "D", "V", "P", "X", "W", "C", "E", "I", "Y", "M", "U", "Z", "S", "J", "A", "H", "B"},  //Rotor 1
        {"K", "C", "L", "Q", "M", "S", "W", "H", "T", "J", "D", "N", "V", "O", "U", "X", "P", "G", "F", "A", "B", "E", "Y", "R", "Z", "I"},  //Rotor 2
        {"F", "A", "C", "X", "V", "R", "M", "S", "U", "O", "Y", "T", "N", "I", "H", "D", "L", "E", "G", "W", "J", "K", "P", "Q", "Z", "B"},  //Rotor 3
        {"I", "L", "W", "Z", "E", "C", "S", "X", "D", "O", "J", "H", "A", "F", "G", "V", "T", "M", "N", "K", "B", "P", "Q", "U", "Y", "R"}}; // Reflector
        // Multidimensional array for the three rotors and reflector

void CharacterEncryption(int input)
{
    int temp;
    temp = * RotorPath[2][input] - 65;
    printf("%d\n", temp);
    temp = * RotorPath[1][temp] - 65;
    printf("%d\n", temp);
    temp = * RotorPath[0][temp] - 65;
    printf("%d\n", temp);
    temp = * RotorPath[3][temp] - 65;
    printf("%d\n", temp);
    temp = * RotorPath[0][temp] - 65;
    printf("%d\n", temp);
    temp = * RotorPath[1][temp] - 65;
    printf("%d\n", temp);
    temp = * RotorPath[2][temp] - 65;
    printf("%d\n", temp);
    printf("%c\n", temp + 65);
    //Function to send a character through the rotors and back and receive decrypted character
}


int main() 
{
    int X;
    scanf(" %c",&X);
    X = X - 65;
    CharacterEncryption(X);
    // Take an input and convers character into number 0-25
    
    
    return 0;
}


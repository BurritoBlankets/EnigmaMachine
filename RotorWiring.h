/************************************************************
*
*  File: RotorWiring.h
*  Author:  Jake Klinger, Jose (Pillo) Duenas-Lopez, Tyler Bruno
*  Version: 1.0 (Mar 25, 2023)
*
*  Purpose:
*            Set hard coded rotors.
*
*************************************************************/

#pragma once
#include <stdio.h>
#include <string.h>

// Multidimensional array for the three rotors and reflector
char *RotorPath[4][26] = {
        {"F", "A", "C", "X", "V", "R", "M", "S", "U", "O", "Y", "T", "N", "I", "H", "D", "L", "E", "G", "W", "J", "K", "P", "Q", "Z", "B"},  //Rotor 3
        {"K", "C", "L", "Q", "M", "S", "W", "H", "T", "J", "D", "N", "V", "O", "U", "X", "P", "G", "F", "A", "B", "E", "Y", "R", "Z", "I"},  //Rotor 2
        {"K", "T", "N", "O", "R", "G", "Q", "L", "F", "D", "V", "P", "X", "W", "C", "E", "I", "Y", "M", "U", "Z", "S", "J", "A", "H", "B"},  //Rotor 1
        {"I", "L", "W", "Z", "F", "E", "S", "X", "A", "O", "U", "B", "R", "Y", "J", "V", "T", "M", "G", "Q", "K", "P", "C", "H", "N", "D"}}; // Reflector

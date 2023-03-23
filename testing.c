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
}
 
int main() 
{
   
    int X = 0,Y = 0, Message_Length;
    char *store;
    
    char Message[100];
    
    printf("Message: ");
    scanf("%s" , &Message);
    
    Message_Length = strlen(Message);
    // Finds length of message
        
        
    for (X = 0; X < 26; X++)
        printf("%s", RotorPath[0][X]);
        printf("\n");
    for (X = 0; X < 26; X++)
    {
        Rotor1Spin();
        printf("\n");
    }
    // The Rotor spinning 26 times
   

int Test, Test2;
    Test = * RotorPath[0][0] - 65;
    printf("%d\n", Test);
    Test2 = * RotorPath[1][Test] - 65;
    printf("%d\n", Test2);
    

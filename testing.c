#include <stdio.h>
#include <string.h>

char *RotorPath[4][26] = {
        {"K", "T", "N", "O", "R", "G", "Q", "L", "F", "D", "V", "P", "X", "W", "C", "E", "I", "Y", "M", "U", "Z", "S", "J", "A", "H", "B"},  //Rotor 1
        {"K", "C", "L", "Q", "M", "S", "W", "H", "T", "J", "D", "N", "V", "O", "U", "X", "P", "G", "F", "A", "B", "E", "Y", "R", "Z", "I"},  //Rotor 2
        {"F", "A", "C", "X", "V", "R", "M", "S", "U", "O", "Y", "T", "N", "I", "H", "D", "L", "E", "G", "W", "J", "K", "P", "Q", "Z", "B"},  //Rotor 3
        {"I", "L", "W", "Z", "E", "C", "S", "X", "D", "O", "J", "H", "A", "F", "G", "V", "T", "M", "N", "K", "B", "P", "Q", "U", "Y", "R"}}; // Reflector
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
   
        
    // Code below moves from letter to letter through rotors and spits back final letter

    int rot3,rot3_2, rot2, rot2_2,rot1, rot1_2,refl;
    
    
    rot3 = * RotorPath[2][0] - 65;
    printf("%d\n", rot3);
    rot2 = * RotorPath[1][rot3] - 65;
    printf("%d\n", rot2);
    rot1 = * RotorPath[0][rot2] - 65;
    printf("%d\n", rot1);
    refl = * RotorPath[3][rot1] - 65;
    printf("%d\n", refl);
    rot1_2 = * RotorPath[3][refl] - 65;
    printf("%d\n", rot1_2);
    rot2_2 = * RotorPath[3][rot1_2] - 65;
    printf("%d\n", rot2_2);
    rot3_2 = * RotorPath[3][rot2_2] - 65;
    printf("%d\n", rot3_2);
    char letter = rot3_2 + 65;
    printf("%c", letter);
  
}

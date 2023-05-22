#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // get message
    string msg = get_string("Message: ");
    int letter, j;
    int len = strlen(msg);
    int bits[BITS_IN_BYTE];
    //looping thorugh eachc charater
    for (int i = 0; i < len; i++)
    {
        //converting charater of msg to a int
        letter = msg[i];
        j = 0;
        while (letter > 0)
        {
            if ( letter % 2 == 0)
                bits[j] = 0;
            else
                bits[j] = 1;
            letter /= 2;
            j++;
        }
        for ( j = 7; j >=0; j--)
        {
            print_bulb(bits[j]);
            bits[j] = 0;
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

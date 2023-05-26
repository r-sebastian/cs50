#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int only_digits(string key);
string rotate(int key, string pt);
int main(int argc, string argv[])
{
    //check if we only have 2 arguments including ./
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //checking argument
    else if (argv[1] < 0)
    {
        printf("Key should be a Positive Number\n");
        return 1;
    }
    //check if arguemts onyl ahve numbers
    else if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //convert the argument into
    else
    {
        int key = atoi(argv[1]);
        //getting the planetext
        string pt = get_string("plaintext: ");
        //convetring to cipher text
        rotate(key,pt);

    }
}

int only_digits(string key)
{
    int len = strlen(key);
    for ( int i = 0; i < len; i++)
        if (isalpha(key[i]))
            return 0;   //if aplha return 0
    return 1; //if no aloha is found  reutn 1
}

string rotate(int key, string pt)
{
    int len = strlen(pt);
    char ct[100];
    for ( int i = 0; i < len; i++)
    {
        if (isalpha(pt[i]))
        {
            if(isupper(pt[i]))A
                ct[i] = ( ( (int)pt[i] + key - 65 ) % 26 ) + 65;
            else
                ct[i] = ( ( (int)pt[i] + key - 97 ) % 26 ) + 97;
        }
        else
            ct[i] = pt[i];
    }
    printf("ciphertext: %s\n",ct);
    return 0;
}
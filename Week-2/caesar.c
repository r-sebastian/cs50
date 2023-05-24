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
        string ct = rotate(key,pt);
        printf("ciphertext: %s\n",ct);
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
    string ct[len];
    int c,ci;
    for ( int i = 0; i < len; i++)
    {
        c = pt[i];
        ci = (c + key ) % 26;
        printf("%c",ci);
    }
    return "ct";
}
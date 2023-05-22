#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);
int print_grade(int l,int w,int s);

int main(void)
{
    int letters,words,sen;
    //sen is variable for sentence
    //get the text
    string text = get_string("Text: ");
    int len = strlen(text);
    //converting all chars into lower case
    for(int i = 0; i < len; i++)
        text[i] = tolower(text[i]);
    letters = count_letters(text);
    words = count_words(text);
    sen = count_sentences(text);
    print_grade(letters,words,sen);
}

int count_letters(string s)
{
    int letters = 0, len = strlen(s);
    //counting everything else other than spaces
    for(int i = 0; i < len; i++)
        if( isalpha(s[i]) )
            letters++;
    return letters;
}

int count_words(string s)
{
    int words = 0, len = strlen(s);
    for(int i = 0; i < len; i++)
        if( isspace(s[i]) )
            words++;
    //adding 1 to words as the loop will only count till last 2nd wrd as it checks for " "
    //last word will not have a space after it
    //You may assume that a sentence:
    //will contain at least one word;
    //will not start or end with a space; and
    //will not have multiple spaces in a row.
    words++;
    return words;
}

int count_sentences(string s)
{
    int sen = 0, len = strlen(s);
    for(int i = 0; i < len; i++)
        if(s[i] == 33 || s[i] == 46 || s[i] == 63)
            sen++;  //variable to sentence
    return sen;
}

int print_grade(int l,int w,int s)
{
    float lpw = 0;  //var for letters per 100 words
    float spw = 0;  //var for sentences per 100 words
    lpw = ( l / (float)w) * 100;
    spw = ( s / (float)w) * 100;
    float index = ( 0.0588 * lpw )- ( 0.296 * spw ) - 15.8;
    index = round(index);
    if ( index >= 16 )
        printf("Grade 16+\n");
    else if( index < 1)
        printf("Before Grade 1\n");
    else
        printf("Grade %i\n",(int)index);
    return 0;
}
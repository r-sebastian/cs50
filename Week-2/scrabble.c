#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    (score1 > score2)? printf("Player 1 wins!") : (score2 > score1)? printf("Player 2 wins!") : printf("Tie!");
    printf("\n");
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    //convert to lowecase
    int i,j;
    int len = strlen(word);
    for(i = 0; i < len; i++)
        word[i] = tolower(word[i]);

    //create a array with alphabets
    char chars[26];
    for(i = 0, j = 97; j <= 122; i++, j++)
        chars[i] = (char)j;

    //check if the user string mathces with the chars[]
    //and adding score
    int score = 0;
    for(i = 0; i < len; i++)
        if(isalpha(word[i]))
            for(j = 0; j < 26; j++)
                if(word[i]==chars[j])
                {
                    score += POINTS[j];
                    break;
                }
    return score;
}

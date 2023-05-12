#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int ht;
    while (1)
    {
        ht= get_int("Height: ");
        if(ht>=1 && ht<=8)
        {
            for(int i=1;i<=ht;i++)
            {
                for(int j=ht;j>i;j--)
                {
                    printf(" ");
                }
                for(int j=0;j<i;j++)
                {
                    printf("#");
                }
                printf("\n");
            }
            break;
        }
        else
            continue;
    }
}
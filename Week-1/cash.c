#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int cents = get_cents();
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;
    int coins = quarters + dimes + nickels + pennies;
    printf("%i\n", coins);
}

int get_cents(void)
{
    int change=0;
    do
    {
        change=get_int("Enter the Change:");
    }while(change<0);
    return change;
}

int calculate_quarters(int cents)
{
    int i=0;
    while(1)
    {
        if(cents-25>=0)
        {
            cents=cents-25;
            i++;
        }
        else
            break;
    }
    return i;
}

int calculate_dimes(int cents)
{
    int i=0;
    while(1)
    {
        if(cents-10>=0)
        {
            cents=cents-10;
            i++;
        }
        else
            break;
    }
    return i;
}

int calculate_nickels(int cents)
{
    int i=0;
    while(1)
    {
        if(cents-5>=0)
        {
            cents=cents-5;
            i++;
        }
        else
            break;
    }
    return i;
}

int calculate_pennies(int cents)
{
    int i=0;
    while(1)
    {
        if(cents-1>=0)
        {
            cents=cents-1;
            i++;
        }
        else
            break;
    }
    return i;
}
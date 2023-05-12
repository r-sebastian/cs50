#include <cs50.h>
#include <stdio.h>

int check_validity(long num);
void check_card_company(long num);
long find_num_reverse(long num);
int find_no_of_digits(long num);

int main(void)
{
    long num=0;
    int nos_of_digits=0;
    //getting the number
    num=get_long("Number:");
    //check if the card is valid
    int validity=check_validity(num);
    if(validity==1)
    {
        //if valid find out which company the card belongs to
        check_card_company(num);
    }
    else
    {
        printf("INVALID\n");
    }
}

int check_validity(long num)
{
    int check=0;
    long backup_num=num;
    int non_mul_nos=0;
    int digit=0;
    int mul_nos=0;
    int sum=0;
    int i=1;
    int mul_no=0;
    int mul_nos_sum=0;
    int mul_no_digit=0;
    while(backup_num>0)
    {
        //extract the last number of the card
        digit=backup_num%10;
        //if i is odd we have the last number i.e nos in the even pos
        //if i is odd we have nos in the even postion
        if(i%2==0)
        {
            //multiplying the digit by 2 and adding them to the previos sum
            mul_no=digit*2;
            while(mul_no>0)
            {
                mul_no_digit=mul_no%10;
                mul_nos_sum+=mul_no_digit;
                mul_no/=10;
            }
        }
        else
        {
            //adding all the other nos which are not multiplied
            non_mul_nos+=digit;
        }
        backup_num/=10;
        i++;
    }
    //adding both the sums
    sum=mul_nos_sum+non_mul_nos;
    //checling if the last number is 0
    if(sum%10==0)
    {
        //when chek is 1 the card is valid by defalut check is 0
        check=1;
    }
    return check;
}

void check_card_company(long num)
{
    long reverse_num=find_num_reverse(num);
    int digits=find_no_of_digits(num);
    int first_digit=reverse_num%10;
    if(first_digit==4)
    {
        if(digits==13 || digits==16)
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    else
    {
        reverse_num=reverse_num/10;
        int second_digit=reverse_num%10;
        int first_two_digits=(first_digit*10)+second_digit;
        if(first_two_digits==34 || first_two_digits==37)
        {
            if(digits==15)
            {
                printf("AMEX\n");
            }
        }
        else if(first_two_digits>=51 && first_two_digits<=55)
        {
            if(digits==16)
            {
                printf("MASTERCARD\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
}

long find_num_reverse(long num)
{
    int digit=0;
    long reverse_num=0;
    while(num>0)
    {
        //reversing the num to make it esier to find the first 2 nums
        //used to find the card company
        digit=num%10;
        reverse_num=(reverse_num*10)+digit;
        num/=10;
    }
    return reverse_num;
}

int find_no_of_digits(long num)
{
    int i=0;
    while(num>0)
    {
        i++;
        num/=10;
    }
    return i;
}
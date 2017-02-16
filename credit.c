#include <stdio.h>
#include <cs50.h>
#include <math.h>

long long int get_credit_number(void);
bool validity_check(long long int credit_number);
void type_check(long long int credit_number);

int main(void)
{
    unsigned long long int credit_number = get_credit_number();
    if (credit_number == 0)
    {
        printf("INVALID\n");
    }
    else
    {
        bool validity = validity_check(credit_number);
        if (validity == 0)
        {
            printf("INVALID\n");
        }
        else
        {
            type_check(credit_number);
        }
    }
}

long long int get_credit_number(void)
{
    printf("Number: ");
    long long int credit_number = get_long_long();
    if (credit_number > 0 && floor(log10(credit_number)) < 16)
    {
        return credit_number;
    }
    return false;
}

bool validity_check(long long int credit_number)
{
    int length = floor(log10(credit_number)) + 1;
    int x;
    int sum = 0;
    for (x = 0 ;x < length; x++)
    {
        if (x % 2 == 0)
        {
            sum += credit_number % 10;
            credit_number /= 10;
        }
        else
        {
            long long int current_digit = (credit_number % 10) * 2;
            if (current_digit > 9)
            {
                sum += current_digit % 10;
                current_digit /= 10;
                sum += current_digit % 10;
                credit_number /= 10;
            }
            else
            {
                sum += current_digit;
                credit_number /= 10;
            }
        }
    }
    if (sum % 10 == 0)
    {
        return true;
    }
    return false;
}

void type_check(long long int credit_number)
{
    int length = floor(log10(credit_number)) + 1;
    int x;
    for (x = 0; x < length - 2; x++)
    {
        credit_number /= 10;
    }
    if ((credit_number / 10) % 10 == 4)
    {
        printf("VISA\n");
    }
    else if ((credit_number % 10 <= 5 && credit_number % 10 >= 1) || credit_number % 10 == 7)
    {
        credit_number /= 10;
        if (credit_number == 5)
        {
            printf("MASTERCARD\n");
        }
        else if (credit_number == 3)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
        
    }
    else
    {
        printf("INVALID\n");
    }
}

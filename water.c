#include <stdio.h>
#include <cs50.h>

int get_minutes(void);
int return_bottles(int minutes);

int main(void)
{
    int minutes = get_minutes();
    int bottles = return_bottles(minutes);
    printf("%i\n", bottles);
}

int get_minutes(void)
{
    printf("Minutes: ");
    int minutes = get_int();
    return minutes;
}

int return_bottles(int minutes)
{
    int bottles = (192 * minutes) / 16;
    return bottles;
}

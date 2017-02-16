#include <stdio.h>
#include <cs50.h>

int get_size(void);
void conditional(int size);
void print_pyramid(int size);

int main(void)
{
    int size = get_size();
    conditional(size);
}

int get_size(void)
{
    printf("Height: ");
    int size = get_int();
    return size;
}

void print_pyramid(int size)
{
    int x;
    int spaces = size;
    for (x = 0; x < size;)
    {
        int y;
        for (y = 0; y < spaces - 1; y++)
        {
            printf(" ");
        }
        spaces -= 1;
        x++;
        int z;
        for (z = 0; z < x; z++)
        {
            printf("#");
        }
        printf("  ");
        for (z = 0; z < x; z++)
        {
            printf("#");
        }
        printf("\n");
    }
}

void conditional(int size)
{
    if (size < 24 && size >= 0)
    {
        print_pyramid(size);
    }
    else
    {
        main();
    }
}

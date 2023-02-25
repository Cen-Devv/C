//*****************************
// ---------------------------*
//        NAME:LUIZ HENRIQUE  *
//        DAY:20/01/2023      *
//        Prog:Credit         *
//----------------------------*
//*****************************
#include <stdio.h>
#include <cs50.h>

//Prototype
int get_height(void);
void create_pyramid(int height);

int main(void)
{
    int value = get_height(); //Storing the value in a variable
    create_pyramid(value); //Calling the create pyramid function
}

//Get height from user
int get_height(void)
{
    int height;
    do
    {
        height = get_int("Height: "); 
    }
    while (height < 1 || height > 8);
    return height;
}

//Function for create pyramid
void create_pyramid(int height)
{
    int counter = height;
    int counter_one = 0;
    for (int v = 0; v < height; v++)
    {
        counter_one++;
        counter--;
        for (int e = 0; e < counter; e++)
        {
            printf(" ");
        }
        for (int h = 0; h < counter_one; h++)
        {
            printf("#");
        }
        printf("  ");
        for (int h2 = 0; h2 < counter_one; h2++)
        {
            printf("#");
        }
        printf("\n");
    }
}
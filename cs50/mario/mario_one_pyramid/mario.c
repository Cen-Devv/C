//*****************************
// ---------------------------*
//        NAME:LUIZ HENRIQUE  *
//        DAY:25/01/2023      *
//        Prog:Credit         *
//----------------------------*
//*****************************

#include <stdio.h>
#include <cs50.h>

//Prototypes
int get_height(void);
void create_pyramid(int height_pyramid);

int main(void)
{
    while (true)
    {
        int value = get_height(); //Storing the value in a variable
        create_pyramid(value); //Calling the create pyramid function
    }

}

//Get height from user
int get_height(void)
{
    int height;
    do
    {
        height =  get_int("Height: ");
    }
    while (height < 1 || height > 8);
    return height;
}

//Function for create pyramid
void create_pyramid(int height_pyramid)
{
    int counter = height_pyramid;
    int counter_one = 0;

    for (int x = 0; x < height_pyramid; x++)
    {
        counter_one++;
        counter--;

        for (int y = 0; y < counter; y++)
        {
            printf(" ");
        }
        for (int z = 0; z < counter_one; z++)
        {
            printf("#");
        }
        printf("\n");
    }
}
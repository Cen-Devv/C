//*****************************
// ---------------------------*
//        NAME:LUIZ HENRIQUE  *
//        DAY:23/02/2023      *
//        Prog:Credit         *
//----------------------------*
//*****************************

#include <stdio.h>
#include <cs50.h>

//Prototypes
int get_numbers(void);

int main(void)
{
    int years = get_numbers();
    printf("Years: %i\n", years);
}

//Functions

//Get parameters
int get_numbers(void)
{
    int size, end_size, years = 0;

    do
    {

        size = get_int("Start size:");


    }
    while (size < 9);

    do
    {
        end_size = get_int("End size:");
    }
    while (end_size < size);

    for (int count = 0; size < end_size; count++)
    {
        size = size + (int)(size / 3) - (int)(size / 4);
        years++;
    }

    return years;
}



    #include <stdio.h>
    #include <math.h>
    #include <cs50.h>

    //Prototypes
    float gent_cents(void);
    int mathematical_process(float cent);

    int main(void)
    {
        float cents = gent_cents(); //cents for arguments
        int result = mathematical_process(cents); //Mathematical processo in argument
        printf("Coins: %i\n", result);
    }

    //get cents from user
    float gent_cents(void)
    {
        float cent = 0;
        while (cent < 0  ||  cent == 0)
        {
            cent = get_float("Change owed: ");
        }
        return cent;
    }

    //Process mathematical is all process for box
    int mathematical_process(float cent)
    {

        int cents = round(cent * 100);
        int Total_coins = 0;
        while (cents > 0)
        {
            if (cents >= 25)
            {
                cents -= 25;
                Total_coins++;
            }
            else if (cents >= 10 && cents <= 24)
            {
                cents -= 10;
                Total_coins++;
            }
            else if (cents >= 5 && cents <= 9)
            {
                cents -= 5;
                Total_coins++;
            }
            else
            {
                cents -= 1;
                Total_coins++;
            }
        }
        return Total_coins;
    }

//*****************************
// ---------------------------*
//        NAME:LUIZ HENRIQUE  *
//        DAY:11/02/2023      *
//        Prog:Credit         *
//----------------------------*
//*****************************

    #include <stdio.h>
    #include <cs50.h>

    //Prototypes
    long GetCardNumber(void);
    long  CheckSum(long card_number);
    void  check_card(long card_number);

    int main(void)
    {
        long card_number = GetCardNumber();
        long card_number_check =  CheckSum(card_number);
        if (card_number_check != 1)
        {
            check_card(card_number_check);
        }
        else
        {
            printf("INVALID\n");
        }

    }
    //Functions

    long GetCardNumber(void)
    {
        long card_number = get_long("Card_number:");
        return card_number;
    }

    //mathematical process for card verification
    long  CheckSum(long card_number)
    {
        long long hundred_power_one = 100, hundred_power_two = 10, hundred_power_three = 10, hundred_power_four = 1, process, process2;
        int  sum_of_number = 0, sum_of_process2 = 0, greater_than_ten = 0, temporary_variable, number_multiplier;

        while (hundred_power_two < card_number)
        {
            process = (unsigned long) card_number % hundred_power_one /  hundred_power_two;
            process2 = (unsigned long) card_number % hundred_power_three / hundred_power_four;
            number_multiplier = process * 2;
            hundred_power_one   *= 100;
            hundred_power_two   *= 100;
            hundred_power_four  *= 100;
            hundred_power_three *= 100;

            if (number_multiplier >= 10)
            {
                //Sum  greater than ten
                temporary_variable = number_multiplier;
                number_multiplier = number_multiplier % 100 / 10;
                greater_than_ten = greater_than_ten + number_multiplier;
                number_multiplier = temporary_variable;
                number_multiplier = number_multiplier % 10 / 1;
                greater_than_ten = greater_than_ten + number_multiplier;
                number_multiplier = 0;
            }
            sum_of_number = sum_of_number + number_multiplier;
            sum_of_process2 = sum_of_process2 + process2;

        }
        sum_of_process2 += card_number % hundred_power_three / hundred_power_four;
        sum_of_number += greater_than_ten;
        sum_of_number += sum_of_process2;

        if (sum_of_number / 1 % 10 == 0)
        {
            return card_number;
        }
        else
        {
            return 1;
        }
    }
    //Card type check
    void check_card(long card_number_check)
    {
        long long hundred_check_one =  10, hundred_check_two = 1, check;
        int digits = 1, two_digits;

        while (hundred_check_one < card_number_check)
        {

            if (card_number_check != 1)
            {


                check = (unsigned long) card_number_check % hundred_check_one / hundred_check_two;
                hundred_check_one *= 10;
                hundred_check_two *= 10;
                digits++;
            }
        }
        hundred_check_one /= 100;
        two_digits = card_number_check / hundred_check_one  % 100;
        if ((digits == 15  && two_digits == 34) || (digits == 15 && two_digits == 37))
        {
            printf("AMEX\n");
        }
        else if ((digits == 16 && two_digits == 51) || (digits == 16 && two_digits == 52) || (digits == 16 && two_digits == 53) ||
                (digits == 16 && two_digits == 54) || (digits == 16 && two_digits == 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((digits == 13 || digits == 16) && (two_digits / 10 % 10 == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
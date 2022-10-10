#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");
    long same_number = 0;
    if ((number >= 4000000000000000 && number < 5000000000000000) || (number >= 4000000000000 && number < 5000000000000))
    {
        int total1 = 0;
        int total2 = 0;
        int num;
        same_number = number;
        for (int i = 0 ; i < 16 ; i += 2)
        {
            number = (number - number % 10) / 10;
            num = (number % 10) * 2;
            if (num < 10)
            {
                //adding the total
                total1 += num;
            }
            else
            {
                // first and second digits
                int first_num = num % 10;
                int second_num = (num - first_num) / 10;
                total1 += first_num;
                total1 += second_num;
            }

            //printf("%li\n", number%10);

            number = (number - number % 10) / 10;
        }
        //printf("%i\n", total1);
        total2 += total1;
        number = same_number;
        for (int i = 0 ; i < 16 ; i += 2)
        {
            total2 += number % 10;
            number = (number - number % 10) / 10;
            //printf("%li\n", number%10);
            number = (number - number % 10) / 10;
        }
        //printf("%i\n", total2);
        if (total2 % 10 == 0)
        {
            //print result
            printf("VISA\n");
        }
        else
        {
            //print result
            printf("INVALID\n");
        }
    }

    else if (number >= 5100000000000000 && number < 5600000000000000)
    {
        //print result

        printf("MASTERCARD\n");
    }
    else if ((number >= 340000000000000 && number < 350000000000000) || (number >= 370000000000000 && number < 380000000000000))
    {
        //print result
        printf("AMEX\n");
    }
    else
    {
        //print result
        printf("INVALID\n");
    }


}
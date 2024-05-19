#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace Text
{
    string NamesNumbers(int number)
    {
        int numbers[101];

        string numberNames[] = {
            "zero",
            "one",
            "two",
            "three",
            "four",
            "five",
            "six",
            "seven",
            "eight",
            "nine",
            "ten",
            "eleven",
            "twelve",
            "thirteen",
            "fourteen",
            "fifteen",
            "sixteen",
            "seventeen",
            "eighteen",
            "nineteen",
            "twenty",
            "twenty-one",
            "twenty-two",
            "twenty-three",
            "twenty-four",
            "twenty-five",
            "twenty-six",
            "twenty-seven",
            "twenty-eight",
            "twenty-nine",
            "thirty",
            "thirty-one",
            "thirty-two",
            "thirty-three",
            "thirty-four",
            "thirty-five",
            "thirty-six",
            "thirty-seven",
            "thirty-eight",
            "thirty-nine",
            "forty",
            "forty-one",
            "forty-two",
            "forty-three",
            "forty-four",
            "forty-five",
            "forty-six",
            "forty-seven",
            "forty-eight",
            "forty-nine",
            "fifty",
            "fifty-one",
            "fifty-two",
            "fifty-three",
            "fifty-four",
            "fifty-five",
            "fifty-six",
            "fifty-seven",
            "fifty-eight",
            "fifty-nine",
            "sixty",
            "sixty-one",
            "sixty-two",
            "sixty-three",
            "sixty-four",
            "sixty-five",
            "sixty-six",
            "sixty-seven",
            "sixty-eight",
            "sixty-nine",
            "seventy",
            "seventy-one",
            "seventy-two",
            "seventy-three",
            "seventy-four",
            "seventy-five",
            "seventy-six",
            "seventy-seven",
            "seventy-eight",
            "seventy-nine",
            "eighty",
            "eighty-one",
            "eighty-two",
            "eighty-three",
            "eighty-four",
            "eighty-five",
            "eighty-six",
            "eighty-seven",
            "eighty-eight",
            "eighty-nine",
            "ninety",
            "ninety-one",
            "ninety-two",
            "ninety-three",
            "ninety-four",
            "ninety-five",
            "ninety-six",
            "ninety-seven",
            "ninety-eight",
            "ninety-nine",
            "one hundred"};
        for (int i = 0; i <= 100; i++)
        {
            numbers[i] = i;
            if (numbers[i] == number)
            {
                return numberNames[i];
            };
        }
    }

    string ConvertNumberToText(int number)
    {
        if (number <= 100)
        {
            return NamesNumbers(number);
        };
        if (number > 100 && number < 1000)
        {
            // 123
            int g1 = number / 100;
            int g2 = number % 100;

            return ConvertNumberToText(g1) + " hundred " + ConvertNumberToText(g2);
        };
        if (number > 1000 && number < 1000000)
        {
            // 123456
            int g1 = number / 1000; // 123
            int g2 = number % 1000; // 456

            return ConvertNumberToText(g1) + " thousand " + ConvertNumberToText(g2);
        };
        if (number >= 1000000 && number < 1000000000)
        {
            // 12345678
            int g1 = number / 1000000; // 1
            int g2 = number % 1000000; // 2

            return ConvertNumberToText(g1) + " million " + ConvertNumberToText(g2);
        };
        // 1 234 567 891
        if (number >= 1000000000)
        {
            int g1 = number / 1000000000; // 1
            int g2 = number % 1000000000; // 234...1

            return ConvertNumberToText(g1) + " billion " + ConvertNumberToText(g2);
        }
    }
}
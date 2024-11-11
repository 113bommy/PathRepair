#!/usr/bin/env

last_digit = [
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
    ]
second_digit = [
    "twenty",
    "thirty",
    "forty",
    "fifth",
    "sixty",
    "seventy",
    "eighty",
    "ninety"
    ]

tens = [
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "forteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen"
    ]

def read_score(x):
    if len(x) == 1:
        return last_digit[int(x)]
    elif x[0] > "1":
        if x[1] == "0":
            return second_digit[int(x[0]) - 2]
        else:
            return "-".join([
                    second_digit[int(x[0]) - 2],
                    last_digit[int(x[1])]
                    ])
    else:
        return tens[int(x) - 10]

score = input()
print(read_score(score))

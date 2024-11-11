n = int(input())
Digits = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"]
Tens = ["ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"]
Teens = ["eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
if n <= 10:
    print(Digits[n])
elif n < 20:
    print(Teens[n - 11])
elif n % 10 == 0:
    print(Tens[n // 10 - 1])
else:
    print(Tens[n // 10 - 1] + "-" + Digits[n % 10])
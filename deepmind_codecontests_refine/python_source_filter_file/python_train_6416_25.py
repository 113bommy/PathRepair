number = int(input())
if number>0:
    if number%10<5:
        number = number-number%10
    else:
        number = number+number%10
else:
    if number%10<5:
        number = number-number%10
    else:
        number = number+(10-number%10)
print(number)

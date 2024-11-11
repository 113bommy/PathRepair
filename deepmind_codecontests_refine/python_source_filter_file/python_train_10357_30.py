number = int(input(""))
if number <= 19:
    if number == 0:
        print('zero')
    elif number == 1:
        print('one')
    elif number == 2:
        print('two')
    elif number == 3:
        print('three')
    elif number == 4:
        print('four')
    elif number == 5:
        print('five')
    elif number == 6:
        print('six')
    elif number == 7:
        print('seven')
    elif number == 8:
        print('eight')
    elif number == 9:
        print('nine')
    elif number == 10:
        print('ten')
    elif number == 11:
        print('eleven')
    elif number == 12:
        print('twelve')
    elif number == 13:
        print('thirteen')
    elif number == 14:
        print('fourteen')
    elif number == 15:
        print('fifteen')
    elif number == 16:
        print('sixteen')
    elif number == 17:
        print('seventeen')
    elif number == 18:
        print('eighteen')
    else:
        print('nineteen')
else:
    if int(number / 10) == 2:
        print('twenty', end="")
    elif int(number / 10) == 3:
        print('thirty', end="")
    elif int(number / 10) == 4:
        print('fourty', end="")
    elif int(number / 10) == 5:
        print('fifty', end="")
    elif int(number / 10) == 6:
        print('sixty', end="")
    elif int(number / 10) == 7:
        print('seventy', end="")
    elif int(number / 10) == 8:
        print('eighty', end="")
    elif int(number / 10) == 9:
        print('ninety', end="")
    if number % 10 == 1:
        print('-one')
    elif number % 10 == 2:
        print('-two')
    elif number % 10 == 3:
        print('-three')
    elif number % 10 == 4:
        print('-four')
    elif number % 10 == 5:
        print('-five')
    elif number % 10 == 6:
        print('-six')
    elif number % 10 == 7:
        print('-seven')
    elif number % 10 == 8:
        print('-eight')
    elif number % 10 == 9:
        print('-nine')
    else:
        print()

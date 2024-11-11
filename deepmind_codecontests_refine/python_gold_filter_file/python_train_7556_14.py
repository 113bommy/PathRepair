import math
number = input()
contador = 0
for i in number:
    if i != '0':
        contador += 1

numberint = int(number)
y = 1
if contador > 1:
    while (numberint / y) > 10 :
        y = y * 10
    resultado = (math.ceil(numberint/y) * y) - numberint
    print('{:d}'.format(resultado))
if contador < 2:
    if numberint <10 :
        print(1)
    else :
        while(numberint/y) > 9:
            y = y * 10
        print('{:d}'.format(y))
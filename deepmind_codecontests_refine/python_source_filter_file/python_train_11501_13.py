from math import floor

tam, soma = [int(i) for i in input().split()]

def canRepresent(tam, soma): return int("9" * tam) >= soma if (tam > 0 and soma > 0) else soma == 0

minimun = []
current = soma

if (soma >= 1 and canRepresent(tam, soma)):
    for i in range(tam):
        digit = 0
        for j in range(0, 10):
            if (i == 0 and j == 0):
                continue
            if (canRepresent(tam - i - 1, current - j)):
                digit = j
                break
        current -= digit
        print(digit, end='')
    print(' ', end='')
    # i = tam - 1
    # while i >= 0:
    #     print(minimun[i], end='')
    #     i -= 1
    current = soma
    for i in range(tam):
        digit = 0
        for j in range(9, -1, -1):
            if (canRepresent(tam - i - 1, current - j)):
                digit = j
                break
        current -= digit
        print(digit, end='')
    print()
elif (soma == 0 and tam == 1):
    print('0 0')
else:
    print('-1 -1')
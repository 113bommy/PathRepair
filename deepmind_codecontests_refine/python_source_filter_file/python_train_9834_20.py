def desenhar_linha(linha, ind):
    print('|', end='')
    for i in range(linha):
        print('O.', end='')
    if ind == 1:
        for i in range(11 - linha):
            print('#.', end='')
        print('|', end='')
    else:
        if 11 - linha == 11:
            print('#', end='')
            linha += 1
        for i in range(11 - linha):
            print('..', end='')
        print('.', end='')


lista = [0,0,0,0]
j = 0
passou = False
k = int(input())
for i in range(k):
    if j == 2 and passou:
        j += 1
    if j == 2:
        passou = True
    lista[j] += 1
    j += 1
    if j == 4:
        j = 0

print('+------------------------+')
desenhar_linha(lista[0], 1)
print('D|)')
desenhar_linha(lista[1], 1)
print('.|')
desenhar_linha(lista[2], 0)
print('.|')
desenhar_linha(lista[3], 1)
print('.|)')
print('+------------------------+')

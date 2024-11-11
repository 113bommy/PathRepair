#Problem A - Little Girl and Maximum XOR

numeros = [int(i) for i in input().split(' ')]
# numeros = [797162752288318119, 908416915938410706]
l = bin(numeros[0])
r = bin(numeros[1])

p = -1
# for i,j in range (len(l),len(r)):
if (len(r) == len(l)):
    for i in range (len(l)):
        if (l[i] != r[i]):
            p = i
            break
    if(numeros[0] != numeros[1]):
        # saida = 2**(len(r) - 2) - 1
        saida = 2**(len(r) - p)
        print(saida)
    else:
        print(0)

else:
    if(numeros[0] != numeros[1]):
        saida = 2**(len(r) - 2) - 1
        # saida = 2**(len(r) - p)
        print(saida)
    else:
        print(0)

# print(bin(numeros[0]))
# print(r)
# print(p)


numero = int(input())

palavra = input()
vetorPalavra = []

for i in range(len(palavra)):
    vetorPalavra.append(0)

apontador = 0
contador = 0
i = 1

while True:
    if apontador+i > len(palavra)-1:
        break

    if palavra[apontador] == palavra[apontador+i]:
        contador +=1
        vetorPalavra[apontador+i] = -1
        i+=1
    else:
        apontador += i+1
        i = 1

paridade = len(palavra) - contador

if paridade%2!=0:
    contador+=1
    print(contador)

    for i in range(len(palavra)-1,-1,-1):
        if vetorPalavra[i] == 0:
            vetorPalavra[i] = -1
            break

    for i in range(len(palavra)):
        if vetorPalavra[i] == 0:
            print(palavra[i],end="")
    print("")
else:
    print(contador)
    for i in range(len(palavra)):
        if vetorPalavra[i] == 0:
            print(palavra[i],end="")
    print("")

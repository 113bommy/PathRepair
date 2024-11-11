n, d = [int(i) for i in input().split()]
lista = [int(i) for i in input().split()]
lista.sort()

if(n == 1):
    print(0)
else:
    pares = []
    x = 0
    while(x<n):
        y = x + 1
        while(y<n):
            g = lista[y] - lista[x]
            if(g <= d):
                pares.append((g,lista[y],lista[x]))
            y+=1
        x+=1
    if pares == []:
        print(0)
    else:
        tamanhoMax = 0
        for upla in pares:
            tamanho = ((n - 1 - lista[::-1].index(upla[1])) - lista.index(upla[2])) + 1
            if(tamanho > tamanhoMax):
                tamanhoMax = tamanho
            print(n - tamanhoMax)


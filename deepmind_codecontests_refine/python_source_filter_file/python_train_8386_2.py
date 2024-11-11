entrada = input().split(" ")
n = int(entrada[0])
m = int(entrada[1])
k = int(entrada[2])

lista = []
nodes = list(map(int, input().split(" ")))

def calc(valor):
    global x, y
    x += 1
    usado[valor] = True
    y += len(lista[valor])
    for i in lista[valor]:
        if not usado[i]:
            calc(i)

for i in range(n):
    lista.append([])
for i in range(m):
    valores = input().split(" ")
    u = int(valores[0])
    v = int(valores[1])
    lista[u - 1].append(v - 1)
    lista[u - 1].append(u - 1)

usado = [False] * n
aux1 = 0
aux2 = -1

for i in range(k):
    global x, y
    x = 0
    y = 0
    calc(nodes[i] - 1)
    aux1 += (x * (x - 1) - y) // 2
    aux2 = max(aux2, x)
    n -= x

aux3 = 0
lenght = len(lista)
for i in range(lenght):
    if not usado[i]:
        aux3 += len(lista[i])

aux1 += ((aux2 + n) * (n + aux2 - 1) - aux2 * (aux2 - 1)) // 2
maximumNumber = aux1 - aux3 // 2

print(maximumNumber)
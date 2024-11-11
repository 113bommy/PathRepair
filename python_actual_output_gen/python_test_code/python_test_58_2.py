maxn = 150035
primos = [0 for x in range(maxn)]

def crivo():
    primos[1] = primos[0] = 1
    for i in range(2, maxn):
        if (primos[i] == 0):
            for j in range(i + i, maxn, i):
                primos[j] = 1
 
    for i in range(maxn-2, -1, -1):
        if (primos[i] != 0):
            primos[i] += primos[i+1]


crivo()
colunas = [0 for x in range(maxn)]

n, m = map(int, input().split())

res = 1e9

for i in range(0, n):
    aux = 0
    linha = list(map(int, input().split()))
    for j in range(m):
        aux += primos[linha[j]]
        colunas[j] += primos[linha[j]]
    if i == n-1:
        for i in range(m):
            res = min(colunas[j], res)
    res = min(aux, res)

print(res)
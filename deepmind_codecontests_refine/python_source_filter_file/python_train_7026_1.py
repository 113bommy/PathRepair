def calculaVizinhos(grafo):
    ciclos = []
    for vertice in grafo:
        for destino1 in grafo[vertice]:
            ciclo = [vertice, destino1]
            for destino2 in grafo[vertice]:
                if destino2 in grafo[destino1]:
                    ciclo.append(destino2)
                    ciclos.append(ciclo)
                    ciclo = [vertice, destino1]

    menor_conhecimento = -1
    for ciclo in ciclos:
        total =sum(list(map(lambda x: len(grafo[x]), ciclo)))
        if total < menor_conhecimento or menor_conhecimento == -1:
            menor_conhecimento = total

    if menor_conhecimento == -1:
        menor_conhecimento = menor_conhecimento - 6
    return menor_conhecimento

n, m = map(int, input().split())
grafo = {}
for i in range(1, n + 1):
    grafo[i] = []
for i in range(m):
    origem, destino = map(int, input().split())
    grafo[origem].append(destino)
    grafo[destino].append(origem)
print(calculaVizinhos(grafo))


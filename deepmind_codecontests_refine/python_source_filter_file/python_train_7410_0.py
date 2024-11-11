from collections import deque


def DFS(x, color, solucion):
    color[x] = 1  # nodo gris
    c=False
    for y,i in adyacentes[x]:
        # el adyacente es blanco
        if color[y] == 0:
            DFS(y, color, solucion)
            solucion[i] = 1  # tendra color 1 porque es v blanco
        # ese adyacente es negro y color 1 porque no es arista de retroceso
        elif color[y] == 2:
            solucion[i] = 1
        # ese adyacente es gris entonces <u,v>  rista de retroceso
        else:
            solucion[i] = 2
            c = True
    color[x] = 2  # nodo negro
    return c


def Solucion():
    color = [0]*n
    solucion = [0]*m
    c=False
    for l in range(0, n):
        if color[l] == 0:
            c=DFS(l, color, solucion) or c
    # como hay ciclos hay que usar dos colores en cada ciclo
    print(2 if c else 1)
    print(*solucion, sep=" ")


# recibiendo la entrada
n, m = map(int, input().split())
adyacentes = [[] for _ in range(0, n)]
for i in range(0, m):
    u, v = map(lambda x: int(x)-1, input().split())
    adyacentes[u].append((v, i))
Solucion()

# Casos de prueba
# 1--
# 4 5
# 1 2
# 1 3
# 3 4
# 2 4
# 1 4
# No hay ciclos

# 2--
#
# 3 3
# 1 2
# 2 3
# 3 1
# Hay un ciclo

# 3--
# 11 12
# 1 8
# 2 5
# 3 7
# 4 6
# 5 3
# 6 10
# 7 8
# 7 2
# 8 11
# 8 9
# 9 1
# 11 3
# Hay tres ciclos por lo q hay tres aristas de retroceso

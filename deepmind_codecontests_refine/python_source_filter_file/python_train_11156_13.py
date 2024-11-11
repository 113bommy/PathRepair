from collections import *

N = 500000
prim, graph = defaultdict(lambda: 1, {i: 1 for i in range(N + 1)}), defaultdict(list)


def count_prime(n):
    prim[0] = prim[1] = 0
    i = 2
    while (i * i <= n):
        if prim[i]:
            for j in range(i * 2, n + 1, i):
                prim[j] = 0
        i += 1

    return list(filter(lambda x: prim[x], prim.keys()))


def form_graph(ext):
    for i in range(1, n):
        graph[i].append(i + 1)
    graph[n].append(1)

    num = 1
    for i in range(ext):
        graph[num].append(num + 2)
        num += 1

    print(n + ext)
    for i in graph.keys():
        for j in graph[i]:
            print(i, j)


n, primes, ext = int(input()), count_prime(N), 0

for i in range(N):
    if prim[n + i]:
        ext = i
        break

form_graph(ext)

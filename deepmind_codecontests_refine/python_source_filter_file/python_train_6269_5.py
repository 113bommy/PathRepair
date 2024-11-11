from sys import stdin
from math import log10,floor,ceil
inp = lambda : stdin.readline().strip()

n, m = [int(x) for x in inp().split()]

adj = [set() for i in range(n)]
for i in range(m):
    u, v = [int(x) for x in inp().split()]
    adj[u-1].add(v-1)
    adj[v-1].add(u-1)
counter = 0
while True:
    toRemove = []
    for i in range(n):
        if len(adj[i]) == 1:
            toRemove.append(i)
            adj[i] = set()
    for i in toRemove:
        for j in range(n):
            if i in adj[j]:
                adj[j].remove(i)
    if len(toRemove) > 1:
        counter += 1
    else:
        break
print(counter)
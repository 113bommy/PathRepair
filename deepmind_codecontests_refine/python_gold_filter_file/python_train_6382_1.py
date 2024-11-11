import sys
input = sys.stdin.readline
from itertools import product
import bisect

class DSU:
    def __init__(self, n):
        self.uf = {i: i for i in range(n)}

    def find(self, x):
        self.uf.setdefault(x, x)
        if self.uf[x] != x:
            self.uf[x] = self.find(self.uf[x])
        return self.uf[x]

    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        self.uf[px] = py

k = int(input())
A = [list(map(int, input().split())) for _ in range(k)]
B = [A[i][i] for i in range(k)]
# dic = {i + 1: A[i][i] for i in range(k)}
par = {i: i for i in range(1, k + 1)}
C = []
ans = []
dsu = DSU(k)
for i in range(k):
    for j in range(i + 1, k):
        C.append((A[i][j], i + 1, j + 1))
C.sort()
for c, i, j in C:
    pi, pj = dsu.find(i), dsu.find(j)
    if pi == pj: continue
    if c > B[pi - 1] and c > B[pj - 1]:
        B.append(c)
        ans.append((pi, len(B)))
        ans.append((pj, len(B)))
        dsu.union(pi, len(B))
        dsu.union(pj, len(B))
    # assert c > B[pj - 1]
    if c == B[pi - 1]:
        ans.append((pj, pi))
        dsu.union(pj, pi)
    elif c == B[pj - 1]:
        ans.append((pi, pj))
        dsu.union(pi, pj)
print(len(B))
print(*B)
print(dsu.find(1))
for a in ans: print(*a)
from itertools import *
n, m = map(int, input().split())
p = [[0] * (m + 1) for i in range(n)] + [[0] * m]
for i in range(n):
    for j, q in enumerate(input()):
        if q == 'S': a, b = i, j
        p[i][j] = '#E'.find(q)
s = list(map(int, input()))
def f(d):
    x, y = a, b
    for k in s:
        i, j = d[k]
        x += i
        y += j
        if p[x][y] + 1: return p[x][y]
    return 0
t = [(1, 0), (-1, 0), (0, 1), (0, -1)]
print(sum(f(d) for d in permutations(t)))
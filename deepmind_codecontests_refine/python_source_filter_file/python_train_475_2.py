from itertools import *
p = {'An': 0, 'Ch': 1, 'Cl': 2, 'Tr': 3, 'Dr': 4, 'Sn': 5, 'He': 6}

def f():
    u, l, v = input().split()
    return p[u[:2]], p[v[:2]]

s = [f() for k in range(int(input()))]
a, b, c = map(int, input().split())

d = l = 9e9
for i in range(1, 6):
    for j in range(1, 7 - i):
        k = 7 - i - j
        t = [a // i, b // j, c // k]
        t = max(t) - min(t)
        if t < d: d, l = t, 0
        if t == d:
            for q in set(permutations([0] * i + [1] * j + [2] * k)):
                l = max(l, sum(q[u] == q[v] for u, v in s))

print(d + 1, l)
# http://codeforces.com/contest/975/problem/D
n, a, b = (int(x) for x in input().split())

marks = 0
k = {}
v = {}
for i in range(0, n):
    x, v1, v2 = [int(x) for x in input().split()]
    ki = v2 - a * v1
    vi = (v1, v2)

    if ki in k:
        k[ki] += 1
    else:
        k[ki] = 1

    if vi in v:
        v[vi] += 1
    else:
        v[vi] = 1

    marks += k[ki] - v[vi]

print(marks * 2)
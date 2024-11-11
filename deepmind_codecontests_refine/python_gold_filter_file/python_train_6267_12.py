import sys
a = int(input())

b = list(map(int, input().split()))
s = sum(b)
if s == 1:
    print(-1)
    sys.exit(0)

k = 1
t = 2
g = []
while t <= s:
    if s % t == 0:
        g.append(t)
    t += 1
l = 0
m = 0
minim = 10 ** 20 + 5
for i in range(len(g)):
    m = 0
    l = 0
    mas = [[] for i in range(s // g[i])]
    for v in range(a):
        if b[v] == 1 and l != g[i]:
            l += 1
            mas[m].append(v)
        elif b[v] == 1 and l == g[i]:
            l = 1
            m += 1
            mas[m].append(v)
        else:
            pass
    h = 0
    for p in range(s // g[i]):
        for z in range(g[i]):
            if z != g[i] // 2:
                h += abs(mas[p][z] - mas[p][g[i] // 2])
    if h < minim:
        minim = h
print(minim)

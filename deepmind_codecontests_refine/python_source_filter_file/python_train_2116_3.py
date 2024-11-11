M = 1e9 + 7
n,m  = map(int, input().split())

p = []
res = 1
for i in range(n):
    p.append(input())


for i in range(m):
    s = set()
    for j in range(n):
        s.add(p[j][i])
    res *= len(s)
print(int(res % M))

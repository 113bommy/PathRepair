m, n = map(int, input().split())
res = m
for i in range(n):
    res -= (i / m) ** n
print(res)
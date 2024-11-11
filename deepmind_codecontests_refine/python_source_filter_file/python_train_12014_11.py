MAXN = 10**6
n = int(input())
A = []
for x in range(1, n):
    A.append(MAXN + x)
print(*A)
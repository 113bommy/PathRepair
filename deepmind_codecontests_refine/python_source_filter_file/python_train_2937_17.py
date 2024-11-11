n, m = map(int, input().split())
a = list(range(1, n+1))
b = list(range(n+1, n+m+1))
if n == 1 and m == 1:
    print(0)
    exit()
if n == 1:
    print(*list(range(1, m+1)))
    exit()
if m == 1:
    print(*list(range(1, n+1)), sep='\n')
    exit()
res = [[0]*m for i in range(n)]
for i in range(n):
    for j in range(m):
        res[i][j] = a[i]*b[j]
for i in res:
    print(*i)

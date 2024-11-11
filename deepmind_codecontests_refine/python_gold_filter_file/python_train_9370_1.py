n = int(input())
g = [[0] * n for _ in range(n)]

while n:
    l = list(map(int, input().split()))
    column_g = g[l[0] - 1]
    for i in l[2:]:
        column_g[i-1] = 1
    n -= 1
for v in g:
    print(*v)
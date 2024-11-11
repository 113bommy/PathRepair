n, m, h = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
ms = [list(map(int, input().split())) for i in range(n)]
for i in range(n):
    if b[i] > 1:
        for j in range(m):
            if (a[j] == b[i] and ms[i][j] != 0) or (ms[i][j] == 1 and a[j] > b[i]):
                ms[i][j] = b[i]
for i in range(m):
    if a[i] > 1:
        for j in range(n):
            if (a[i] == b[j]and ms[j][i] != 0) or (ms[j][i] == 1 and a[i] < b[j]):
                ms[j][i] = a[i]
for i in ms:
    print(*i)

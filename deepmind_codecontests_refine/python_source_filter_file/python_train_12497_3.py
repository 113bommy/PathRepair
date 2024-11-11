n, m, l = map(int,input().split())
a = [list(map(int, input().split()))for i in range(n)]
b = [list(map(int, input().split()))for j in range(m)]
num = [[0 for i in range(l)]for j in range(n)]
for k in range(n):
    for i in range(l):
        for j in range(m):
            num[k][i] += a[k][j] * b[j][i]
for i in range(n):
    print(" ".join(map(num[i])))



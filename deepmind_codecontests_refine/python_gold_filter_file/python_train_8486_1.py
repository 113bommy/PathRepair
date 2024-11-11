n, k = map(int, input().split())
arr = [[0 for i in range(n)] for j in range(n)]
c = n * n
s = 0
for i in range(n):
    #arr[i][n - 1] = c
    #c -= 1
    for j in range(n - 1, k - 2, -1):
        arr[i][j] = c
        c -= 1
    s += c + 1
for i in range(n):
    for j in range(k - 2, -1, -1):
        arr[i][j] = c
        c -= 1
print(s)
for i in arr:
    print(*i)

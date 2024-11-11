n, k = [int(t) for t in input().split()]
k -= 1

lst = [[0 for t in range(n)] for t in range(n)]
for col in range(n-1, k-1, -1):
    for row in range(n):
        lst[row][col] = n*n - (n-1-col) - row*(n-k)

for col in range(k-1, -1, -1):
    for row in range(n):
        lst[row][col] = n*k - (k-1-col) - row*(n-1-k)

print(sum([lst[i][k] for i in range(n)]))
for i in range(n):
    for k in range(n):
        print(lst[i][k], end=' ')
    print()
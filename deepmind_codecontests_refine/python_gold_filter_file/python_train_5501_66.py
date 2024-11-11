n, m, k = map(int, input().split())

for i in range(1+n):
    for j in range(1+m):
        if i*m + j*n - 2*i*j == k:
            print('Yes')
            exit(0)
print('No')


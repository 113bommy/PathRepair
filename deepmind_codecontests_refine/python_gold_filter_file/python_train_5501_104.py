n, m, k = list(map(int, input().split()))
for i in range(n+1):
    for j in range(m+1):
        if m*i + n*j - 2*(i*j) == k:
            print('Yes')
            exit()
print('No')

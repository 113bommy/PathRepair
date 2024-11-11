n,m,k = list(map(int,input().split()))
ans = 'No'
for i in range(n):
    for j in range(m):
        if i * m + j * n - 2 * i * j == k:
            ans = 'Yes'
print(ans)

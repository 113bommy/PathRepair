n,m,k = list(map(int,input().split()))
ans = 'No'
for i in range(n+1):
    for j in range(m+1):
        if i * m + j * n - 2 * i * j == k:
            ans = 'Yes'

print(ans)

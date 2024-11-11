n, m, k = map(int, input().split())
ans = 'No'
for i in range(1, n+1):
    for j in range(1, m+1):
        if i*(m-j)+j*(n-i)==k:
            ans = 'Yes'
            break
print(ans)  
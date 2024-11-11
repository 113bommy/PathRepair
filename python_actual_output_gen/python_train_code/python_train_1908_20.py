n,m,k = map(int,input().split())
ans = 'No'
for i in range(m+1):
  for j in range(n+1):
    if i*n + j*m - i*j == k:
       ans = 'Yes'
print(ans)

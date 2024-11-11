n,m,k=map(int,input().split())
for i in range(n):
  for j in range(m):
    if i*m+j*n-i*j==k:
      print('Yes')
      quit()
print('No')
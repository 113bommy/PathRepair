import sys
n,m,k=map(int,input().split())
for i in range(n):
  for j in range(m):
    if (i*j)+(n-i)*(m-j)==k:
      print('Yes')
      sys.exit()
print('No')
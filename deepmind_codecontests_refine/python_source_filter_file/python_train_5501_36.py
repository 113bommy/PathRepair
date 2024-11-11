n,m,k=map(int,input().split())
f=False
for i in range(n+1):
  for j in range(m+1):
    if (m-i)*j+(n-j)*i==k:
      f=True
if f:
  print('Yes')
else:
  print('No')
n,m,k = map(int,input().split())
for a in range(n+1):
  for b in range(m+1):
    if k == a*m+b*n-2*a*b:
      print('Yes')
      exit()
print('No')
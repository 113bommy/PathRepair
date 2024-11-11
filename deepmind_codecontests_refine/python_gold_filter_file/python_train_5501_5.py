n,m,k = map(int,input().split())
for x in range(n+1):
  for y in range(m+1):
    if (n-x)*y+(m-y)*x==k:
      print('Yes')
      exit()
print('No')
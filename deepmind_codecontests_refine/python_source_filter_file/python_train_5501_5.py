n,m,k = map(int,input().split())
for x in range(1,n+1):
  for y in range(1,m+1):
    if (n-x)*y+(m-y)*x==k:
      print('Yes')
      exit()
print('No')
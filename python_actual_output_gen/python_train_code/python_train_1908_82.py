n,m,b = map(int,input().split())
for i in range(1,n+1):
  for j in range(1,m+1):
    tmp = i * m + j * n - i * j * 2
    if tmp == b:
      print('Yes')
      exit()
      
print('No')
    
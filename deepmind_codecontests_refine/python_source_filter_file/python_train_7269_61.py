n,y = map(int,input().split())
for i in range(n+1):
  for j in range(n+1):
    if (y - 1000*i - 5000*j)/10000 == n-i-j and n-i-j>=0:
      print(i,j,n-i-j)
      exit()
print(-1,-1,-1)
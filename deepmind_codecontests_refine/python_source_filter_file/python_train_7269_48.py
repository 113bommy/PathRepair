n,y=map(int,input().split())
for i in range(n):
  for j in range(i,n):
    k=n-i-j
    if i*10000+j*5000+k*1000==y:
      print(i,j,k)
      exit()
print(-1,-1,-1)

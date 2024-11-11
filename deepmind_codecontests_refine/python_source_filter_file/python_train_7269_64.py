n,y=map(int,input().split())
x,y,z=-1,-1,-1
for i in range(n+1):
  for j in range(n+1-i):
    k=n-i-j
    if i*10000+j*5000+k*1000==n:
      x,y,z=i,j,k
print(x,y,z)
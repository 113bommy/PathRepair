n,a=map(int,input().split())
for i in range(n+1):
  for j in range(n-i+1):
    z=n-i-j
    if (10000*i)+(5000*j)+(1000*z)==a:
      print(i,j,z)
      exit()
print(-1,-1,-1)
    
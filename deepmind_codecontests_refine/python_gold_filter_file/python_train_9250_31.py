n,k,x,y=(int(input()) for _ in range(4))
if n<=k:
  print(n*x)
else:
  print(k*x+(n-k)*y)
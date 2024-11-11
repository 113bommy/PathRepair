n,k,x,y=[int(input()) for i in range(4)]
if n>=k:
  print(x*k+y*(n-k))
else:
  print(x*n)
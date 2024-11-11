n,k=map(int,input().split())
t=(n+1)//2
if k>t:
  print(2*(k-t))
else:
  print(2*k-1)
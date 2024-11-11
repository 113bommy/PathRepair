n,k=map(int,input().split())
t=(n+1)//2
if k<t:
  print(2*k-1)
else:
  print(2*k-2*t)
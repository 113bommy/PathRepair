n,k=map(int,input().split())
t=n//2 +n%2
if k<=t:
  print(2*k-1)
elif k<=n:
  print((k-t)*2)

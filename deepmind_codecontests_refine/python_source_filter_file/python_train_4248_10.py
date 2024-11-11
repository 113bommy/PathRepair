n=int(input())
w=10
ans=0
if n%2==0:
  while w<n:
    ans+=n/w
    w=w*5
  print(ans)
else:
  print(0)

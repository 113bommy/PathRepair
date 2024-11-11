a,b=map(int,input().split())
c=abs(a+b)
if c%2==0:
  print(c//2)
else:
  print("IMPOSSIBLE")
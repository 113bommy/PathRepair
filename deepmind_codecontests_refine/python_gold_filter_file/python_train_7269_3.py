import sys
n,y =map(int,input().split())
for a in range(n+1):
  for b in range(n+1-a):
    if 10000*a+5000*b+1000*(n-a-b) == y:
      print(a,b,n-a-b)
      sys.exit()
print(-1,-1,-1)

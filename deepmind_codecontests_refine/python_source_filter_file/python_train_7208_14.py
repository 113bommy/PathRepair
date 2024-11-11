# a = list(map(int,input().split()))
# map(int,input().split())
import math
for _ in " "*int(input()):
  n,m,k=map(int,input().split())
  if m==0:
    print(0)
  else:
    if (n//k) < m:
      x=n//k
      print(math.ceil((m-x)/(k-1)))
    else:
      print(m)
  


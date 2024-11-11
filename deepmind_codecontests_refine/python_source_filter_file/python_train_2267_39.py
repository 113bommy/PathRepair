X,N = map(int,input().split())
A = list(map(int,input().split()))
import sys
for d in range(X+1):
  for i in [1,-1]:
    B = X + d*i
    if A.count(B) == 0:
      print(B)
      sys.exit()
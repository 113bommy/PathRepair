import math
N = int(input())
M = (math.ceil((math.sqrt(1+8*N)-1)/2))
for m in range(0,M):
  if M-m <= N:
    print(M-m)
    N -= M-m
  else:
    if N!=0:
      print(N)
    break
import math
for t in range(int(input())):
  n=int(input())
  abc=list(map(int, input().split()))
  c=0
  for i in range(1,n):
    if abc[i]-abc[i-1]<0:
      c=max(int(math.log((abc[i-1]-abc[i]),2))+1,c)
      abc[i]+=c
  print(c)
  
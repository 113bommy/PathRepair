n=int(input())
x,y=map(int,input().split())

import math
for i in range(n-1):
  t,a=map(int,input().split())
  tbai=(x-1/t+1)
  abai=y-1/a+1
  bai=max(tbai,abai)
  x=t*bai
  y=a*bai
  #print(x,y)
print(x+y)
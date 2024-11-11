R,D = map(int,input().split())
n = int(input())

from math import sqrt

cnt = 0
for i in range(n):
  x,y,r = map(int,input().split())

  p = x*x+y*y
  if (D+r)**2 <= p <= (R-r)**2:
    cnt += 1

print(cnt)
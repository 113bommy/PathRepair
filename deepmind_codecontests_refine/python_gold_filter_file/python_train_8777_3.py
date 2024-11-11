import sys
input=sys.stdin.readline
from math import gcd
from collections import defaultdict
def lcm(a,b):
  return a*b//gcd(a,b)
t=int(input())
for _ in range(t):
    n,a,b=map(int,input().split())
    if a==1:
      if (n-1)%b==0:
        print("Yes")
      else:
        print("No")
      continue
    s=set()
    x=1
    while x<=n:
      s.add(x%b)
      x*=a
    for m in s:
      if (n-m)%b==0:
        print("Yes")
        break
    else:
      print("No")
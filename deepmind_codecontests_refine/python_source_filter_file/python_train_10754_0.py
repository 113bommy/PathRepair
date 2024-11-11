import math
import sys
input=sys.stdin.readline
t=int(input())
for i1 in range(t):
  # n=int(input())
  # l=list(map(int,input().split()))
  n,k1,k2=map(int,input().split())
  w,b=map(int,input().split())
  if 2*w>k1+k2 or 2*b>2*n-k1+k2:
    print("NO")
  else:
    print("YES")  
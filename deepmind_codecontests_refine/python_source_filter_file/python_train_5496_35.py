n=int(input())
import sys
d=0
now=0
input=sys.stdin.readline
for i in range(n):
  a,b=map(int,input().split())
  now+=a*b
  d+=b
print(now//9+d-1)
  

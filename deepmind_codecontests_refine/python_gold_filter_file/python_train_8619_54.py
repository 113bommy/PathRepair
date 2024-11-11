import sys
from heapq import heappush,heappop
input=sys.stdin.readline
n,q=map(int,input().split())
e=[]
for i in range(n):
  s,t,x=map(int,input().split())
  e.append((s-x,1,x))
  e.append((t-x,-1,x))
for i in range(q):
  d=int(input())
  e.append((d,2,0))
e.sort()
s=set()
a=[]
for time_,type_,x_ in e:
  if type_==1:
    s.add(x_)
    heappush(a,x_)
  elif type_==-1:
    s.remove(x_)
  else:
    while a and a[0] not in s:
      heappop(a)
    if a:
      print(a[0])
    else:
      print(-1)
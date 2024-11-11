from collections import defaultdict
import math

def culcD(a,b):
  x1,y1,r1=a
  x2,y2,r2=b
  return max(0,math.sqrt((x1-x2)**2+(y1-y2)**2)-(r1+r2))

A=[]

xs,ys,xg,yg=map(int,input().split())
A.append((xs,ys,0))
A.append((xg,yg,0))

V=defaultdict(int)
V[(0,1)]=(culcD(A[0],A[1]))
V[(1,0)]=(culcD(A[0],A[1]))

N=int(input())
for i in range(N):
  x,y,r=map(int,input().split())
  A.append((x,y,r))
  for j in range(len(A)-1):
    dist = culcD(A[j],A[-1])
    V[(i+2,j)]=dist
    V[(j,i+2)]=dist

def dijkstra(n):
  d=[float('inf')]*(n+2)
  d[0]=0
  used=[False]*(n+2)
  
  while True:
    v=-1
    for i in range(n+2):
      if used[i]==False and (v==-1 or d[i] < d[v]):
        v=i
    if v==-1:
      break
    used[v]=True
    for j in range(n+2):
      d[j]=min(d[j],d[v]+V[(j,v)])

  return d[1]

print(dijkstra(N))
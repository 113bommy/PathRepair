from copy import *
import sys
def init(N,node,A,unit,func):
  n=1
  while n<N:
    n<<=1
  for i in range(n*2-1):
    if len(node)<=i:
      node.append(deepcopy(unit))
    else:
      node[i]=deepcopy(unit)
  for i in range(len(A)):
    node[n-1+i]=deepcopy(A[i])
  for i in range(n-2,-1,-1):
    node[i]=func(node[(i<<1)+1],node[(i<<1)+2])
  node.append(func)
  node.append(unit)
  node.append(n)

def upd(node,x,a):
  y=node[-1]+x
  node[y-1]=a
  while y>1:
    y=y>>1
    node[y-1]=node[-3](node[(y<<1)-1],node[y<<1])

def query(node,l,r):
  x,y=l,r
  z=node[-1]-1
  rr=deepcopy(node[-2])
  rl=deepcopy(node[-2])
  while True:
    if x==y:
      return node[-3](rl,rr)
    if x&1:
      rl=node[-3](rl,node[x+z])
      x+=1
    if y&1:
      rr=node[-3](node[y+z-1],rr)
    if z==0:
      return node[-3](rl,rr)
    x>>=1
    y>>=1
    z>>=1

def bis_min_k(node,k,cond):
  x=k+1
  while True:
    if node[-1]<=x:
      return x-node[-1]
    if cond(node[(x<<1)-1]):
      x=x<<1
    else:
      x=(x<<1)+1

def bis_min(node,l,r,cond):
  x,y=l,r
  z=node[-1]-1
  for i in range(30):
    if x+(1<<i)>y:
      break
    if x&(1<<i):
      if cond(node[z+(x>>i)]):
        return bis_min_k(node,z+(x>>i),cond)
      x+=(1<<i)
    if z==0:
      break
    z>>=1
  for i in range(29,-1,-1):
    if i and ((node[-1]-1)>>(i-1))==0:
      continue
    if x+(1<<i)>y:
      continue
    if (y-x)&(1<<i):
      if cond(node[((node[-1]-1)>>i)+(x>>i)]):
        return bis_min_k(node,((node[-1]-1)>>i)+(x>>i),cond)
      x+=(1<<i)
  return node[-1]

input=sys.stdin.buffer.readline
INF=(10**9)+7
for t in range(int(input())):
  sega=[]
  segb=[]
  segarev=[]
  segbrev=[]
  N=int(input())
  A=list(map(int,input().split()))
  init(N,sega,A[:],0,lambda x,y:max(x,y))
  init(N,segb,A[:],INF,lambda x,y:min(x,y))
  init(N,segarev,A[::-1],0,lambda x,y:max(x,y))
  init(N,segbrev,A[::-1],INF,lambda x,y:min(x,y))
  X=[INF]*N
  for i in range(N):
    ra=bis_min(sega,i+1,N,lambda x:x>=A[i])
    rb=bis_min(segb,i+1,N,lambda x:x<=A[i])
    la=N-1-bis_min(segarev,N-i,N,lambda x:x>=A[i])
    lb=N-1-bis_min(segarev,N-i,N,lambda x:x<=A[i])
    if 0<=la<N and 0<=rb<N:
      X[la]=min(X[la],rb)
    if 0<=lb<N and 0<=ra<N:
      X[lb]=min(X[lb],ra)
  seg=[]
  init(N,seg,[],INF,lambda x,y:min(x,y))
  l=0
  ANS=0
  for r in range(N):
    upd(seg,r,X[r])
    while seg[0]<=r:
      upd(seg,l,INF)
      l+=1
    ANS+=r-l+1
  print(ANS)
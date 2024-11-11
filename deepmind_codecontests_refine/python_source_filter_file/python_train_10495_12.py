from collections import defaultdict
import sys
sys.setrecursionlimit(100000)
d=defaultdict(int)
dw=defaultdict(int)
n,m=map(int,input().split())
l=[]
for i in range(n):
  l.append(list(input()))
lb=[[0 for i in range(m)]for j in range(n)]
move=[[1,0],[-1,0],[0,1],[0,-1]]
def dfs(n1,n2,w,n3):
  if lb[n1][n2]!=0:
    return None
  else:
    lb[n1][n2]=n3
    if w==".":
      w1="#"
    else:
      w1="."
    for j in move:
      dx=j[0]
      dy=j[1]
      x=dx+n1
      y=dy+n2
      if 0>x or x>n-1 or y<0 or y>m-1:
        pass
      else:
        if w1!=l[x][y]:
          pass
        else:
          dfs(x,y,w1,n3)
    return None
dfs(0,0,l[0][0],1)
num=1
for i in range(n):
  for j in range(m):
    dfs(i,j,l[i][j],num)
    num+=1
for i in range(n):
  for j in range(m):
    d[lb[i][j]]+=1
    if l[i][j]=="#":
      dw[lb[i][j]]+=1
ans=0
for i in d:
  ans+=dw[i]*(d[i]-dw[i])
print(ans)
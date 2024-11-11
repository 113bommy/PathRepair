import sys
sys.setrecursionlimit(300000)
n,k=map(int,input().split())
a=list(map(int,input().split()))

def dfs(index, lx):
  if index < 1:
    return lx
  b=[0]*n
  for i in range(n):
    l=max(0,i-lx[i])
    g=min(n-1,i+lx[i])
    b[l]+=1
    if g+1<n:
      b[g+1]-=1
  for i in range(1,n):
    b[i]+=b[i-1]
  return dfs(index-1,b)
    
print(*dfs(min(k,44),a))


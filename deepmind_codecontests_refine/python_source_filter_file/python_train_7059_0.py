import sys
sys.setrecursionlimit(10**9)
mod=10**9+7
m,n=map(int,input().split())
grid=[list(input()) for _ in range(n)]
cache={}
def dp(i,j):
  if i<0 or j<0 or i>=len(grid) or j>=len(grid[0]) or grid[i][j]=='#':
    return 0
  elif (i,j) in cache:
    return cache[(i,j)]
  elif i==m-1 and j==n-1:
    return 1
  cache[(i,j)]=dp(i+1,j)+dp(i,j+1)
  return cache[(i,j)]

print(dp(0,0)%mod) 
  
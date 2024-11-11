 import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf') ;mod = 998244353
mans = 998244353 ;ans = 0 ;count = 0 ;pro = 1
sys.setrecursionlimit(10**6)

n = int(input())
XD = [tuple(map(int,input().split())) for i in range(n)]
XD.append((-10**10,inf))
XD.sort()

now = 0
visited1 = [] 
def dfs(node):
  visited1.append(node)

  global now
  pro = 1
  while now < n :
    if XD[now+1][0] < XD[node][0] + XD[node][1]:
      now += 1
      pro *= dfs(now)
      pro %= mod
    else:break
  return pro + 1
ans = dfs(0)
print((ans-1)%mod)



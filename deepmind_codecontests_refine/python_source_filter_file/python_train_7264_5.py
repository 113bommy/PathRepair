#!/usr/bin/env python3
import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf') ;mod = 998244353
mans = inf ;ans = 0 ;count = 0 ;pro = 1
sys.setrecursionlimit(10**6)

n = int(input())
XD = [(-10**10,inf)]
for i in range(n):
  x,d = map(int,input().split())
  XD.append((x,d))
XD.sort()
visited = [0] * (n+1)
def dfs(node):
  visited[node] = 1
  res = 1
  i = node + 1
  while i < n+1:
    if XD[i][0] < XD[node][0] + XD[node][1]:
      if visited[i]:continue
      pro,i = dfs(i)
      res *= pro
      res %= mod
    else: break
  # print(node,res+1)
  return res + 1 , i
print((dfs(0)[0]-1)%mod)
# print(visited)
# print(XD)
# dfs(1)
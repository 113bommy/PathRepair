import sys
sys.setrecursionlimit(10**7)

n = int(input())
uvw = [list(map(int,input().split())) for _ in range(n-1)]

e =[[] for _ in range(n)]
color = [-1]*n

dw = {}
for u,v,w in uvw:
  e[u-1].append(v-1)
  e[v-1].append(u-1)
  dw[(u-1,v-1)] = dw[(v-1,u-1)] = w

def dfs(i,c)  :
  color[i] = c
  for ei in e[i]:
    if color[ei] != -1:
      continue
      dfs(ei, c+dw[(i,ei)])

dfs(0,0)   

for c in color:
  print(c%2)
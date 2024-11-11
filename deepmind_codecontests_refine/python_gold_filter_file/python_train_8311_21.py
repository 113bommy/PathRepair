import sys
input = sys.stdin.readline
import heapq
from collections import deque
sys.setrecursionlimit(200000)

N = int(input())
X = [[] for _ in range(N)]
for i in range(N-1):
  a = int(input())
  X[a-1].append(i+1)
  
# dfsをして、Depthを計算しつつ、depth大きい順に取り出せるようにheapqを使う
h = []

seen = [False] * N
def dfs(a,depth):
  seen[a] = True
  heapq.heappush(h, (-depth, a))
  for nxt in X[a]:
    #if seen[nxt]:
      #continue
    dfs(nxt, depth+1)

dfs(0,0)
#rint(len(h))
DP = [0] * N
while h:
  depth, a = heapq.heappop(h)
  cand = []
  for child in X[a]:
    cand.append(DP[child])
  if not cand:
    DP[a] = 1
    continue
  cand.sort(reverse=True)
  for i in range(len(cand)):
    DP[a] = max(DP[a], cand[i]+i+1)
    
print(DP[0]-1)
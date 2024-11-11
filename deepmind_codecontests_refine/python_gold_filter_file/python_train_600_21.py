import sys
from heapq import heapify, heappop, heappush
MAX_INT = int(10e15)
MIN_INT = -MAX_INT
mod = 1000000007
sys.setrecursionlimit(1000000)
def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(sys.stdin.readline())
def S(): return input()

N, M = IL()
LRC = [IL() for _ in range(M)]

root = [[(0, i-1)] for i in range(N+1)] #(cost, vertex)
for i in range(M):
  L, R, C = LRC[i]
  root[L].append((C, R))
#print(root)
data = []
heappush(data, (0, 1)) #(total_cost, vertex)
ans = [MAX_INT]*(N+1)
ans[1] = 0
finished = [False]*(N+1)
finished[0] = True

while data:
  nowcost, v = heappop(data)
  #print(nowcost, v)
  if finished[v] == False:
    finished[v] = True
    for edge, nextv in root[v]:
      if ans[nextv] < nowcost + edge:
        continue
      else:
        ans[nextv] = nowcost + edge
        heappush(data, (nowcost + edge, nextv))
      #print(ans)
if finished[N] == True:
  print(ans[N])
else:
  print(-1)
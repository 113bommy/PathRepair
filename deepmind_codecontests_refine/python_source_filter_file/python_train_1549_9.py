import sys
stdin = sys.stdin

def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

from collections import deque
from collections import defaultdict

def bfs(graph:list, start:int) -> list:
    # 未探索のノードは距離null
    node = len(graph)
    dist = [None]*node
    
    # 始点ノードの距離を0とし、bfsのためのqueueを作成
    dist[start] = 0
    que = deque([(0,start)])
    
    # 未探索のノードをqueueに入れる
    # kより大きいの距離のものを数える
    while que:
        cost, cur_node = que.popleft()

        for nex_cost, nex_node in graph[cur_node]:
            if dist[nex_node] is not None:
                continue
            else:
                dist[nex_node] = dist[cur_node] + nex_cost
                que.append((dist[nex_node], nex_node))
                
    return dist
  
# 入力, グラフ作成
n,k = li()
adj_list = [[] for _ in range(n)]
edges = []
for _ in range(n-1):
    a,b = li_()
    adj_list[a].append((1,b))
    adj_list[b].append((1,a))
    edges.append((a,b))

ans = n
dists = []
for i in range(n):
    dists.append(bfs(adj_list, i))
# kが奇数の時
if k%2:
    for a,b in edges:
        ans = min(ans, sum([min(d1,d2) > (k-1)//2 for d1,d2 in zip(dists[a], dists[b])]))
    
# kが偶数の時
else:
    for st in range(n):
        ans = min(ans, sum([d > k//2 for d in dists[i]]))

print(ans)
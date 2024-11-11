import sys
stdin = sys.stdin
 
sys.setrecursionlimit(10**5) 
 
def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

from collections import defaultdict, deque

# 入力・隣接リスト作成
n,m = li()
graph = defaultdict(set)
geta = pow(10,7)

for _ in range(m):
    p,q,c = li()
    
    graph[p + c*geta].add(q + c*geta)
    graph[q + c*geta].add(p + c*geta)
    
    graph[p + c*geta].add(p)
    graph[q + c*geta].add(q)
    
    graph[p].add(p + c*geta)
    graph[q].add(q + c*geta)
    
que = deque()
que.append((0, 1))
visited = set()

ans = -1

while que:
    (cost, node) = que.popleft()
    
    if node in visited:
        continue
    
    elif node % geta == n:
        ans = cost
        break
    
    visited.add(node)
    
    
    for nex in graph[node]:
        if nex in visited:
            continue
        
        elif node <= n and nex > n:
            que.append((cost+1, nex))
            
        else:
            que.appendleft((cost, nex))
    
print(ans)
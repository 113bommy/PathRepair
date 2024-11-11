import string
import math
import collections 

def bfs(graph,start,v,tab):
    Q = collections.deque([start])
    mi = 1000*1000
    while len(Q) != 0:
        cur = Q[0]
        Q.popleft()
        v[cur] = 1
        mi = min(mi,tab[cur])
        for nei in graph[cur]:
            if not v[nei]:
                Q.append(nei)
    return mi
            

def main():
    n,m = map(int,input().split())
    tab = list(map(int,input().split()))
    graph = [[] for x in range(n)]
    v = [0]*n
    s = 0
    for x in range(m):
        a,b = map(int,input().split())
        a-=1
        b-=1
        graph[a].append(b)
        graph[b].append(a)
    for x in range(n):
        if not v[x]:
            s += bfs(graph,x,v,tab)
    print(s)
main()
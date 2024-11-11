import sys
from heapq import heappop, heappush

class Edge:
    def __init__(self, u, v, cap, flow, cost, rev):
        self.u = u
        self.v = v
        self.cap = cap
        self.flow = flow
        self.cost = cost
        self.rev = rev

def add_edge(adj, u, v, capv, flowv, costv):
    adj[u].append(Edge(u, v, capv, flowv, costv, len(adj[v])))
    adj[v].append(Edge(v, u, 0, flowv, -costv, len(adj[u])-1))

def match(crossword, cw_idx, word):
    for k in range(len(word)):
        if crossword[cw_idx + k] != word[k]:
            return False
    
    return True

def read_input():
    n = int(sys.stdin.readline())
    crossword = sys.stdin.readline()[:-1]
    m = int(sys.stdin.readline())
    
    adj = [[] for _ in range(n+2)]

    for _ in range(m):
        word, p = sys.stdin.readline().split()
        p = int(p)

        i = 0
        while i + len(word) <= n:
            if match(crossword, i, word):
                u, v = i + 1, i + 1 + len(word)
                add_edge(adj, u, v, 1, 0, -p)

            i += 1

    x = int(sys.stdin.readline())

    for i in range(n + 1):
        u, v = i, i + 1
        add_edge(adj, u, v, x, 0, 0)
        
    return adj

def bellman_ford(adj):
    potential = [0] * len(adj)

    for _ in range(len(adj)):
        for u in range(len(adj)):
            for e in adj[u]:
                reduced_cost = potential[e.u] + e.cost - potential[e.v]
                if e.cap > 0 and reduced_cost < 0:
                    potential[e.v] += reduced_cost
    
    return potential

def dijkstra(adj, potential, s, t):
    oo = float('inf')
    dist, pi = [+oo] * len(adj), [None] * len(adj)

    dist[s] = 0
    heap = [(0, s)]

    while heap:
        du, u = heappop(heap)

        if dist[u] < du: continue
        if u == t: break

        for e in adj[u]:
            reduced_cost = potential[e.u] + e.cost - potential[e.v]
            if e.cap - e.flow > 0  and dist[e.v] > dist[e.u] + reduced_cost:
                dist[e.v] = dist[e.u] + reduced_cost
                heappush(heap, (dist[e.v], e.v))
                pi[e.v] = e
    
    return dist, pi

def min_cost_max_flow(adj):
    min_cost, max_flow = 0, 0
    oo = float('inf')

    potential = bellman_ford(adj)

    s, t = 0, len(adj) - 1
    while True:
        dist, pi = dijkstra(adj, potential, s, t)
        
        if dist[t] == +oo:
            break
            
        for u in range(len(adj)):
            if dist[u] < dist[t]:
                potential[u] += dist[u] - dist[t]
        
        limit, v = +oo, t
        while v:
            e = pi[v]
            limit = min(limit, e.cap - e.flow)
            v = e.u
        
        v = t
        while v:
            e = pi[v]
            e.flow += limit
            # adj[v][e.rev].flow -= limit
            v = e.u
        
        min_cost += limit * (potential[t] - potential[s])
        max_flow += limit
    
    return min_cost, max_flow

adj  = read_input()

min_cost, _ = min_cost_max_flow(adj)
print(-min_cost)
from heapq import heappop, heappush
from sys   import stdin
 
def graph (ne) :
    g = {}
    for i in range(ne) :
        u, v, w = [int(t) for t in input().split()]
        if u not in g :
            g[u] = {}
        if v not in g :
            g[v] = {}
        if v not in g[u] :
            g[u][v] = w
            g[v][u] = w
        else :
            g[u][v] = min(g[u][v], w)
            g[v][u] = min(g[v][u], w)
    return g
 
def search (g, bv, ev) :
    pq = []
    ps = {bv : bv}
    ws = {bv : 0}
    heappush(pq, (0, bv))
 
    while pq :
        u = heappop(pq)[1]
        if u == ev :
            return ps
        if u not in g :
            continue
        for v in g[u] :
            cw = ws[u] + g[u][v]
            if (v not in ws) or (cw < ws[v]) :
                heappush(pq, (cw, v))
                ps[v] = u
                ws[v] = cw
 
    return {}
 
def path (bv, ev, ps) :
    p = [ev]
    while bv != ev :
        ev = ps[ev]
        p.append(ev)
    return p
 
for s in stdin :
    nv, ne = [int(t) for t in s.split()]
    bv     = nv
    ev     = 1
    g      = graph(ne)
    ps     = search(g, bv, ev)
    if ps == {} :
        print(-1)
    else :
        p = path(bv, ev, ps)
        for v in p :
            print(v, end = " ")
        print()
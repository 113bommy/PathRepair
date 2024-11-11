import sys
        
def getpar(Edge, p):
    N = len(Edge)
    par = [0]*N
    par[0] = -1
    par[p]  -1
    stack = [p]
    visited = set([p])
    while stack:
        vn = stack.pop()
        for vf in Edge[vn]:
            if vf in visited:
                continue
            visited.add(vf)
            par[vf] = vn
            stack.append(vf)
    return par

def topological_sort_tree(E, r):
    Q = [r]
    L = []
    visited = set([r])
    while Q:
        vn = Q.pop()
        L.append(vn)
        for vf in E[vn]:
            if vf not in visited:
                visited.add(vf)
                Q.append(vf)
    return L

def getcld(p):
    res = [[] for _ in range(len(p))]
    for i, v in enumerate(p[1:], 1):
        res[v].append(i)
    return res


        

N, M = map(int, input().split())
Edge = [[] for _ in range(N)]
for _ in range(N-1):
    a, b = map(int, sys.stdin.readline().split())
    a -= 1
    b -= 1
    Edge[a].append(b)
    Edge[b].append(a)

P = getpar(Edge, 0)
L = topological_sort_tree(Edge, 0)
C = getcld(P)

dp1 = [1]*N
for l in L[N-1:0:-1]:
    p = P[l]
    dp1[p] = (dp1[p]*(dp1[l]+1)) % M

dp2 = [1]*N
dp2[0] = dp1[0]
info = [0]*(N+1)

vidx = [0]*N
vmull = [None]*N
vmulr = [None]*N
for i in range(N):
    Ci = C[i]
    res = [1]
    for j, c in enumerate(Ci, 1):
        vidx[c] = j
        res.append(res[-1] * (1+dp1[c]) % M)
    vmulr[i] = res + [1]
    res = [1]
    for c in Ci:
        res.append(res[-1] * (1+dp1[c]) % M)
    vmull[i] = [1] + res[::-1]
for l in L[1:]:
    p = P[l]
    pp = P[p]
    vi = vidx[l]
    res = vmulr[p][vi-1] * vmull[p][vi+1] % M
    res = res*(1+info[pp]) % M
    dp2[l] = dp1[l]*(res+1) % M
    info[p] = res % M

print(*dp2, sep = '\n')

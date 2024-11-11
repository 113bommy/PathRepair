import sys
from heapq import heapify, heappop, _heapify_max, heappush, _heappop_max

f = sys.stdin

def line():
    return f.readline().strip().split()

class UnionFind:
    def __init__(self, n):
        self.link = [-1]*n
        self.rank = [0]*n

    def add_link(self,node,parent):
        self.link[node] = parent

    def find(self,x):
        l = []
        node = x
        parent = self.link[node]
        
        while parent != -1:
            l.append(node)
            node = parent
            parent = self.link[node]

        for element in l:
            self.link[element] = node

        return node
    
    def union(self,u,v):
        root_u = self.find(u)
        root_v = self.find(v)
        if root_u == root_v:
            return False
        rank_u = self.rank[root_u]
        rank_v = self.rank[root_v]
        if rank_u == rank_v:
            self.link[root_v] = root_u
            self.rank[root_u] += 1
        elif rank_u < rank_v:
            self.link[root_u] = root_v
        else:
            self.link[root_v] = root_u
        return True

def solve():
    
    s=sum(v for v in A)
    if s<(N-1)*X:
        return "NO"

    res=[]
    q = [(-a,i) for i,a in enumerate(A)]
    heapify(q)
    uf = UnionFind(N)
    rem=[False]*N
    
    while len(q)>1:
        a,comp = heappop(q)
        if rem[uf.find(comp)]:
            continue
        a=-a
        root_comp = uf.find(comp)

        while G[root_comp]:        
            tgt,r = G[root_comp].pop()
            root_tgt = uf.find(tgt)
            if root_comp==root_tgt:
                continue
            
            tot = A[root_comp] + A[root_tgt] - X
            if tot>=0:
                uf.union(root_comp,root_tgt)
                
                new_root = uf.find(root_comp)
                A[new_root] = tot
                G[new_root].extend(G[root_tgt] if new_root==root_comp else G[root_comp])
                rem[root_tgt if new_root==root_comp else root_comp] = True
                heappush(q,(-tot,new_root))
                res.append(r)
                break
    
    
    return str("YES\n"+ '\n'.join(str(v) for v in res))


T = 1
for test in range(1,T+1):
    N,M,X = map(int,line())
    A = list(map(int,line()))
    
    G=[[] for _ in range(N)]
    for r in range(1,M+1):
        i,j = map(int,line())
        G[i-1].append((j-1,r))
        G[j-1].append((i-1,r))

    print(solve())
    
f.close()
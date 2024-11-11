import sys
input = sys.stdin.readline
from collections import defaultdict

class Unionfind:
    def __init__(self, n):
        self.par = [-1]*n
        self.rank = [1]*n
    
    def root(self, x):
        p = x
        
        while not self.par[p]<0:
            p = self.par[p]
        
        while x!=p:
            tmp = x
            x = self.par[x]
            self.par[tmp] = p
        
        return p
    
    def unite(self, x, y):
        rx, ry = self.root(x), self.root(y)
        
        if rx==ry: return False
        
        if self.rank[rx]<self.rank[ry]:
            rx, ry = ry, rx
        
        self.par[rx] += self.par[ry]
        self.par[ry] = rx
    
        if self.rank[rx]==self.rank[ry]:
            self.rank[rx] += 1
    
    def is_same(self, x, y):
        return self.root(x)==self.root(y)
    
    def count(self, x):
        return -self.par[self.root(x)]

N, M = map(int, input().split())
a = list(map(int, input().split()))
uf = Unionfind(N)

for _ in range(M):
    x, y = map(int, input().split())
    uf.unite(x, y)

d = defaultdict(list)
rs = set()

for i in range(N):
    r = uf.root(i)
    rs.add(r)
    d[r].append(a[i])

if len(rs)==1:
    print(0)
    exit()

if 2*(len(rs)-1)>N:
    print('Impossible')
    exit()
    
ans = 0

for k in d.keys():
    d[k].sort()
    ans += d[0]

l = []

for v in d.values():
    l += v[1:]

l.sort()
ans += sum(l[:len(rs)-2])

print(ans)
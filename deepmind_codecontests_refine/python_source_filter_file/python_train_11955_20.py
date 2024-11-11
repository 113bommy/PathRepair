import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
from heapq import heappop,heappush

n,m = map(int,readline().split())
a = list(map(int,readline().split()))
xy = list(map(int,read().split()))

if(n-m==1):
    print(0)
    exit()

p = ((n-1)-m)*2
if( p > n):
    print('Impossible')
    exit()

sys.setrecursionlimit(10**9)

class UnionFind():
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n

    def find(self,x):
        if(self.parents[x] < 0):
            return x
        self.parents[x] = self.find(self.parents[x])
        return self.parents[x]

    def size(self, x):
        return self.parents[ self.find(x) ] * -1

    def same(self, x, y):
        x_root = self.find(x)
        y_root = self.find(y)
        return (x_root == y_root)

    def union(self,x,y):
        x_root = self.find(x)
        y_root = self.find(y)
        if(x_root == y_root):
            return

        if( self.parents[x_root] <= self.parents[y_root] ):
            self.parents[x_root] += self.parents[y_root]
            self.parents[y_root] = x_root
        else:
            self.parents[y_root] += self.parents[x_root]
            self.parents[x_root] = y_root

    def members(self,x):
        root = self.find(x)
        ret = [ i for i in range(self.n) if self.find(i) == root ]
        return ret

    def roots(self):
        ret = [ i for i in range(self.n) if self.parents[i] < 0]
        return ret

    def group_count(self):
        return len(self.roots())

    def all_group_members(self):
        return {r: self.members(r) for r in self.roots()}

uf = UnionFind(n)
hqs = [[] for _ in range(n)]

it = iter(xy)
for x,y in zip(it,it):
    uf.union(x,y)

for i in range(n):
    root = uf.find(i)
    heappush(hqs[root], a[i])

ans = []
others = []
for i in range(n):
    if(hqs[i]):
        ans.append(heappop(hqs[i]))
        # others += hqs[i]
        others.axtend(hqs[i])

others.sort()
rem = p - len(ans)
# ans += others[:rem]
ans.extend(others[:rem])

print(sum(ans))
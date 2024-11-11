import sys
input = sys.stdin.readline

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))

    def find(self, a):
        acopy = a
        while a != self.parent[a]:
            a = self.parent[a]
        while acopy != a:
            self.parent[acopy], acopy = a, self.parent[acopy]
        return a

    def union(self, a, b):
        self.parent[self.find(b)] = self.find(a)

n, m = map(int, input().split())
UF = UnionFind(n)
for _ in range(m):
    a,b = map(int, input().split())
    UF.union(a-1,b-1)
o=set()
for i in range(n):
    o.add(UF.fins(i))
print(len(o) - 1)
class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n)]
        self.node_size = [1] * n
        self.edge_size = [0] * n
        self.rank = [0] * n

    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    def same_check(self, x, y):
        return self.find(x) == self.find(y)

    def get_node_size(self, x):
        return self.node_size[self.find(x)]

    def get_edge_size(self, x):
        return self.edge_size[self.find(x)]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            self.edge_size[x] += 1
        else:
            if self.rank[x] < self.rank[y]:
                self.par[x] = y
                self.edge_size[y] += self.edge_size[x] + 1
                self.node_size[y] += self.node_sizes[x]
            else:
                self.par[y] = x
                self.edge_size[x] += self.edge_size[y] + 1
                self.node_size[x] += self.node_size[y]
                if self.rank[x] == self.rank[y]:
                    self.rank[x] += 1

n, m = [int(item) for item in input().split()]
UF = UnionFind(n)
for i in range(m):
    x, y = [int(item) - 1 for item in input().split()]
    UF.union(x, y)

unconnected_node = 0
unconnected_edge = 0
seen = set()
p0 = UF.find(0)
p1 = UF.find(1)
for i in range(n):
    pi = UF.find(i)
    if pi != p0 and pi != p1:
        if pi not in seen:
            unconnected_edge += UF.edge_size[pi]
            unconnected_node += UF.node_size[pi]
            seen.add(pi)

if UF.get_node_size(0) > UF.get_node_size(1):
    large = 0
    small = 1
else:
    large = 1
    small = 0

A = UF.get_node_size(large) + unconnected_node
B = UF.get_node_size(small)
ans = A * (A - 1) // 2 + B * (B - 1) // 2
ans -= UF.get_edge_size(large) + UF.get_edge_size(small) + unconnected_edge
print(ans)
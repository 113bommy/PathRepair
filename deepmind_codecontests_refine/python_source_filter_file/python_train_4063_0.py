class DisjoinSet:
    def __init__(self, size):
        self.rank = [0 for _ in range(size)]
        self.p = [0 for _ in range(size)]
        for i in range(n):
            self.makeSet(i)

    def makeSet(self, x):
        self.p[x] = x
        self.rank[x] = x

    def same(self, x, y):
        print(int(self.findSet(x) == self.findSet(y)))

    def unite(self, x, y):
        self.link(self.findSet(x), self.findSet(y))

    def link(self, x, y):
        if self.rank[x] > self.rank[y]:
            self.p[y] = x
        else:
            self.p[x] = y
            if self.rank[x] == self.rank[y]:
                self.rank[y] += 1

    # ???????±???????
    def findSet(self, x):
        if x != self.p[x]:
            self.p[x] = self.findSet(self.p[x])
        return self.p[x]


if __name__ == '__main__':
    n, q = map(int, input().split())
    D = DisjoinSet(n)
    cmd = {0: lambda x, y: D.unite(x, y), 1: lambda x, y: D.same(x, y)}
    for _ in range(q):
        c, x, y = map(int, input().split())
        cmd[c](x, y)
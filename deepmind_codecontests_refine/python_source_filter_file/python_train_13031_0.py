import sys
input = sys.stdin.readline
import collections
class UnionFind:
    def __init__(self):
        self.parent = {}

    def add(self, e):
        self.parent[e] = e

    def find(self, e):
        #if self.parent[e] == e: return e
        #p = self.find(self.parent[e])
        #self.parent[e] = p
        #return p
        p = e
        while self.parent[p] != p: p = self.parent[p]
        self.parent[e] = p
        return p

    def union(self, e1, e2):
        self.parent[self.find(e1)] = self.find(e2)

    def getDepth(self, e):
        depth = 0
        p = e
        while self.parent[p] != p:
            depth += 1
            p = self.parent[p]
        return depth


def minGuest(n, guests):
    uf = UnionFind()
    for e in range(1, n + 1): uf.add(e)
    if n == 100000 and len(guests) == 99999: print('cp1')
    for e1, e2 in guests: uf.union(e1, e2)
    if n == 100000 and len(guests) == 99999: print('cp2')
    m = collections.defaultdict(int)
    for e in range(1, n + 1):
        if n == 100000 and len(guests) == 99999:
            print(e)
            print(uf.getDepth(e))
        m[uf.find(e)] += 1
    if n == 100000 and len(guests) == 99999: print('cp3')
    #print(m)
    ne = 0
    for _, cnt in m.items(): ne += cnt - 1
    return len(guests) - ne

def main():
    n, k = input().split()
    guests = []
    for _ in range(int(k)):
        a, b = input().split()
        guests.append([int(a), int(b)])
    print(minGuest(int(n), guests))

if __name__ == '__main__':
    main()
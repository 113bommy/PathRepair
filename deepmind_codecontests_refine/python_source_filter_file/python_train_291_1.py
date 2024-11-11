import sys
sys.setrecursionlimit(2000000)
input = sys.stdin.readline
class UnionFind():
    def __init__(self,n):
        self.n=n
        self.parents = [i for i in range(n+1)]
        #dist[x]はxとその親との間の距離を保持している
        self.dist = [0]*(n+1)
    def find(self,x):
        if self.parents[x]==x:
            return x
        else:
            a = self.parents[x]
            self.parents[x]=self.find(self.parents[x])
            self.dist[x] += self.dist[a]
            return self.parents[x]
    def unite(self,l,r,d):
        rRoot = self.find(r)
        lRoot = self.find(l)
        if rRoot == lRoot:
            if self.dist[l] - self.dist[r] != d:
                print("No")
                exit()
        else:
            #rRootとlRoot、どちらが親になるべきか決める
            newLDist = d + self.dist[r]
            if newLDist>=self.dist[l]:
                self.parents[lRoot] = rRoot
                self.dist[lRoot] = newLDist-self.dist[l]
            else:
                self.parents[rRoot] = LRoot
                self.dist[rRoot] = self.dist[l]-newLDist

N,M = map(int,input().split())
tree = UnionFind(N)
for _ in range(M):
    l,r,d = map(int,input().split())
    tree.unite(l,r,d)
print("Yes")
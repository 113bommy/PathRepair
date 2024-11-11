class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n)) #親ノード
        self.size = [1]*n #グループの要素数
 
    def root(self, x): #root(x): xの根ノードを返す．
        while self.parent[x] != x:
            self.parent[x] = self.parent[self.parent[x]]
            x = self.parent[x]
        return x 
 
    def merge(self, x, y): #merge(x,y): xのいる組とyのいる組をまとめる
        x, y = self.root(x), self.root(y)
        if x == y: return False
        if self.size[x] < self.size[y]: x,y=y,x #xの要素数が大きいように
        self.size[x] += self.size[y] #xの要素数を更新
        self.parent[y] = x #yをxにつなぐ
        return True
 
    def issame(self, x, y): #same(x,y): xとyが同じ組ならTrue
        return self.root(x) == self.root(y)
        
    def getsize(self,x): #size(x): xのいるグループの要素数を返す
        return self.size[self.root(x)]


# coding: utf-8
# Your code here!
import sys
readline = sys.stdin.readline
read = sys.stdin.read

n = int(readline())
xyi = []

for i in range(n):
    x,y = map(int,readline().split())
    xyi.append((x,y,i))

UF = UnionFind(n)
xyi.sort(key = lambda p:p[0])
#print(xyi)

q = []
for x,y,i in xyi:
    print(q)
    if q and q[-1][0] < y: Y,I = q[-1]
    else: Y,I = y,i
    while q and q[-1][0] < y:
        yy,ii = q.pop()
        UF.merge(i,ii)
    q.append((Y,I))
    #print(i,idx)

for i in range(n):
    print(UF.getsize(i))


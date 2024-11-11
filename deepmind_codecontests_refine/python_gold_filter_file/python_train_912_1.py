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

############################################################################
############################################################################
# coding: utf-8
# Your code here!
import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline
read = sys.stdin.read

n,m = [int(i) for i in readline().split()]
d = [int(i) for i in readline().split()]

g = [[] for _ in range(n)]
a = map(int,read().split())

for i,(u,v) in enumerate(zip(a,a)):
    u -= 1; v -= 1
    g[u].append((v,i))
    g[v].append((u,i))

INF = 10**9
ans = [INF]*m #辺のコスト

UF = UnionFind(2*n+1) #二部グラフ構成のため

dd = [(c,i) for i,c in enumerate(d)]
dd.sort()

"""
コストが小さい順に、以下を行う
　コスト以下の点があれば、辺を結び、breakする
　なければアウト
"""
for c,idx in dd:
    for (v,j) in g[idx]:
        if d[v] <= c:
            UF.merge(v,idx+n)
            UF.merge(v+n,idx)
            ans[j] = c
            break
    else:
        print(-1)
        exit()

#UF に超頂点を加えて、二部グラフの塗分けをする
s = []
T = 2*n
for i in range(n):
    if UF.issame(T,i):
        s.append("W")
    elif UF.issame(T,i+n):
        s.append("B")
    else:
        s.append("W")
        UF.merge(T,i)
                
print("".join(s))
print(*ans,sep="\n")

    

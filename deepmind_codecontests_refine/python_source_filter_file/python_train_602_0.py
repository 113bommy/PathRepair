class UnionFindVerSize():
    def __init__(self, N,init):
        """ N個のノードのUnion-Find木を作成する """
        # 親の番号を格納する。自分が親だった場合は、自分の番号になり、それがそのグループの番号になる
        self._parent = [n for n in range(0, N)]
        self._size = [1] *N
        # グループのサイズ（個数）
        self._weight=init
        self._set=[[0,0] for i in range(N)]

    def find_root(self, x):
        """ xの木の根(xがどのグループか)を求める """
        if self._parent[x] == x: return x
        self._parent[x] = self.find_root(self._parent[x]) # 縮約
        return self._parent[x]

    def unite(self, x, y):
        """ xとyの属するグループを併合する """
        gx = self.find_root(x)
        gy = self.find_root(y)

        if gx == gy:return

        # 小さい方を大きい方に併合させる（木の偏りが減るので）
        if self._size[gx] < self._size[gy]:
            self._parent[gx] = gy
            self._weight[gy]+=self._weight[gx]
            self._size[gy]+=self._size[gx]
            self._set[gy][0]+=self._set[gx][0]
            self._set[gy][1]+=self._set[gx][1]

        else:
            self._parent[gy] = gx
            self._weight[gx]+=self._weight[gy]
            self._size[gy]+=self._size[gx]
            self._set[gx][0]+=self._set[gy][0]
            self._set[gx][1]+=self._set[gy][1]

    def add(self,i,u,key):
        x=self.find_root(u)
        if key:
            self._set[x][0]+=self._set[x][1]+1
            self._set[x][1]=0
        else:
            self._set[x][1]+=1

    def get_size(self, x):
        """ xが属するグループのサイズ（個数）を返す """
        return self._size[self.find_root(x)]

    def get_weight(self,x):
        return self._weight[self.find_root(x)]

    def get_set(self,x):
        return self._set[self.find_root(x)]

    def is_same_group(self, x, y):
        """ xとyが同じ集合に属するか否か """
        return self.find_root(x) == self.find_root(y)

    def calc_group_num(self):
        """ グループ数を計算して返す """
        N = len(self._parent)
        ans = 0
        for i in range(N):
            if self.find_root(i) == i:
                ans += 1
        return ans

import sys

input=sys.stdin.readline

N,M=map(int,input().split())
weight=list(map(int,input().split()))
edge=[]
for i in range(M):
    u,v,c=map(int,input().split())
    edge.append((c,u-1,v-1))
edge.sort()

uf=UnionFindVerSize(N,weight)
for i in range(M):
    c,u,v=edge[i]
    uf.unite(u,v)
    uf.add(i,u,uf.get_weight(u)>=c)

no=uf.get_set(0)[1]
print(no)
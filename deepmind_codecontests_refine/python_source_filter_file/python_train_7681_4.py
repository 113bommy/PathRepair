class UnionFind:
    """
    sizeによる実装
    """

    def __init__(self, N):
        self.parent = [i for i in range(N)]
        self.size = [1 for _ in range(N)]

    def find(self, x):
        """
        x: child
        ret-> node
        xのグループの代表を見つける
        """
        if self.parent[x] == x:
            return x
        else:
            return self.find(self.parent[x])

    def union(self, x, y):
        """
        union (x ,y)
        x,y: node
        ret->None
        """
        px = self.find(x)
        py = self.find(y)
        if px == py:
            return
        if self.size[px] < self.size[py]:
            self.parent[px] = py
            self.size[py] += self.size[px]
        else:
            self.parent[py] = px
            self.size[px] += self.size[py]

    def same(self, x, y):
        """
        return true if x and y are in same group
        """
        return self.find(x) == self.find(y)

    def connectedNum(self, x):
        """
        return size of the group x belong to
        """
        return self.size[self.find(x)]

    def is_connected(self):
        """
        return true is all node is in one group
        """
        return self.connectedNum(0) == len(self.parent)

    def componentNum(self):
        """
        return componentNum
        """
        par_set=set()
        for p in self.parent:
            par_set.add(self.find(p))
        return len(par_set)

class SegmentTree():
    '''
    非再帰
    segment tree
    '''

    def __init__(self, n, func, init=float('inf')):
        '''
        n->配列の長さ
        func:func(a,b)->val,　func=minだとRMQになる
        木の高さhとすると,
        n:h-1までのノード数。h段目のノードにアクセスするために使う。
        data:ノード。
        parent:k->child k*2+1とk*2+2
        '''
        self.n = 2**(n-1).bit_length()
        self.init = init
        self.data = [init]*(2*self.n)
        self.func = func

    def set(self, k, v):
        '''
        あたいの初期化
        '''
        self.data[k+self.n-1] = v

    def build(self):
        '''
        setの後に一斉更新
        '''
        for k in reversed(range(self.n-1)):
            self.data[k] = self.func(self.data[k*2+1], self.data[k*2+2])

    def update(self, k, a):
        '''
        list[k]=aに更新する。
        更新ぶんをrootまで更新
        '''
        k += self.n-1
        self.data[k] = a

        while k > 0:
            k = (k-1)//2
            self.data[k] = self.func(self.data[k*2+1], self.data[k*2+2])

    def query(self, l, r):
        '''
        [l,r)のfuncを求める
        '''
        L = l+self.n
        R = r+self.n
        ret = self.init
        while L < R:
            if R & 1:
                R -= 1
                ret = self.func(ret, self.data[R-1])
            if L & 1:
                ret = self.func(ret, self.data[L-1])
                L += 1
            L >>= 1
            R >>= 1
        return ret


N,K = map(int,input().split())
P = list(map(int,input().split()))


Seg_min = SegmentTree(N,min)
Seg_max = SegmentTree(N,max,0)
for i,p in enumerate(P):
    Seg_min.set(i,p)
    Seg_max.set(i,p)
Seg_min.build()
Seg_max.build()

inc=[0]*(N+1)
for i in range(N-1):
    if P[i+1]>P[i]:
        inc[i+1]=1

for i in range(N):
    if inc[i+1]!=0:
        inc[i+1]+=inc[i]

Un=UnionFind(N-K+1)
sorted_seg_par=None

for i in range(N-K+1):
    #start=iとする
    if inc[i+K-1]>=K-1:#[i,i+K]はsorted
        if sorted_seg_par is None:
            sorted_seg_par=i
        else:
            Un.union(sorted_seg_par,i)
    elif i+1<N-K and P[i]==Seg_min.query(i,i+K+1) and P[i+K]==Seg_max.query(i,i+K+1):#[i,i+K]と[i+1,i+K+1]はequivalent
        Un.union(i,i+1)
print(Un.componentNum())


#####segfunc#####
def segfunc(x, y):
    if y[0]>x[0]:
        return x
    else:
        return y
#################

#####ide_ele#####
ide_ele =(float("inf"),-1)
#################

class SegTree:
    """
    init(init_val, ide_ele): 配列init_valで初期化 O(N)
    update(k, x): k番目の値をxに更新 O(logN)
    query(l, r): 区間[l, r)をsegfuncしたものを返す O(logN)
    """
    def __init__(self, init_val, segfunc, ide_ele):
        """
        init_val: 配列の初期値
        segfunc: 区間にしたい操作
        ide_ele: 単位元
        n: 要素数
        num: n以上の最小の2のべき乗
        tree: セグメント木(1-index)
        """
        n = len(init_val)
        self.segfunc = segfunc
        self.ide_ele = ide_ele
        self.num = 1 << (n - 1).bit_length()
        self.tree = [ide_ele] * 2 * self.num
        # 配列の値を葉にセット
        for i in range(n):
            self.tree[self.num + i] = init_val[i]
        # 構築していく
        for i in range(self.num - 1, 0, -1):
            self.tree[i] = self.segfunc(self.tree[2 * i], self.tree[2 * i + 1])

    def update(self, k, x):
        """
        k番目の値をxに更新
        k: index(0-index)
        x: update value
        """
        k += self.num
        self.tree[k] = x
        while k > 1:
            self.tree[k >> 1] = self.segfunc(self.tree[k], self.tree[k ^ 1])
            k >>= 1

    def query(self, l, r):
        """
        [l, r)のsegfuncしたものを得る
        l: index(0-index)
        r: index(0-index)
        """
        res = self.ide_ele

        l += self.num
        r += self.num
        while l < r:
            if l & 1:
                res = self.segfunc(res, self.tree[l])
                l += 1
            if r & 1:
                res = self.segfunc(res, self.tree[r - 1])
            l >>= 1
            r >>= 1
        return res

import heapq

N=int(input())
p=list(map(int,input().split()))
n=N//2
op=[(p[2*i+1],2*i+1) for i in range(n)]
ep=[(p[2*i],2*i) for i in range(n)]

oseg=SegTree(op,segfunc,ide_ele)
eseg=SegTree(ep,segfunc,ide_ele)

def first(l,r):
    if l>=r:
        return (-1,-1,-1,-1)
    if l%2==0:
        val,index=eseg.query(l//2,r//2)
        val2,index2=oseg.query(index//2,r//2)
        return (val,val2,index,index2)
    else:
        val,index=oseg.query(l//2,r//2)
        val2,index2=eseg.query(index//2+1,r//2+1)
        return (val,val2,index,index2)

val,val2,index,index2=first(0,N)
que=[((val,val2),0,N)]
heapq.heapify(que)
ans=[]
while que:
    tuple,l,r=heapq.heappop(que)
    ans.append(tuple[0])
    ans.append(tuple[1])
    val,val2,index,index2=first(l,r)
    val,val2,l,r=first(l,index)
    if val!=-1:
        heapq.heappush(que,((val,val2),l,index))
    val,val2,l,r=first(index+1,index2)
    if val!=-1:
        heapq.heappush(que,((val,val2),index+1,index2))
    val,val2,l,r=first(index2+1,r)
    if val!=-1:
        heapq.heappush(que,((val,val2),index2+1,r))

print(*ans)
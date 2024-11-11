import sys,collections as cl,bisect as bs
sys.setrecursionlimit(100000)
input = sys.stdin.readline
mod = 10**9+7
Max = sys.maxsize
def l(): #intのlist
    return list(map(int,input().split()))
def m(): #複数文字
    return map(int,input().split())
def onem(): #Nとかの取得
    return int(input())
def s(x): #圧縮
    a = []
    aa = x[0]
    su = 1
    for i in range(len(x)-1):
        if aa != x[i+1]:
            a.append([aa,su])
            aa = x[i+1]
            su = 1
        else:
            su += 1
    a.append([aa,su])
    return a
def jo(x): #listをスペースごとに分ける
    return " ".join(map(str,x))
def max2(x): #他のときもどうように作成可能
    return max(map(max,x))
def In(x,a): #aがリスト(sorted)
    k = bs.bisect_left(a,x)
    if k != len(a) and a[k] ==  x:
        return True
    else:
        return False
"""
def nibu(x,n,r):
    ll = 0
    rr = r
    while True:
        mid = (ll+rr)//2

    if rr == mid:
        return ll
    if (ここに評価入れる):
        rr = mid
    else:
        ll = mid+1

"""

import collections
import itertools
import operator


class UnionFind:
    def __init__(self, x):
        class KeyDict(dict):
            def __missing__(self, key):
                self[key] = key
                return key

        self.parent = KeyDict()
        self.rank = collections.defaultdict(int)
        self.size = collections.defaultdict(lambda: 1)
        if x is not None:
            for elem in range(x+1):
                _, _, _ = self.parent[elem], self.rank[elem],self.size[elem]

    def find(self, x):
        if self.parent[x] == x:
            return x
        else:
            self.parent[x] = self.find(self.parent[x])
            return self.parent[x]

    def unite(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if not self.are_same(x,y):
            xx = self.size[x]
            yy = self.size[y]
            if self.rank[x] < self.rank[y]:
                self.parent[x] = y
                self.size[y] += xx
            else:
                self.parent[y] = x
                self.size[x] += yy
        if self.rank[x] == self.rank[y]:
            self.rank[x] += 1

    def Size(self,x):
        return self.size[self.find(x)]

    def are_same(self, x, y):
        '''print(x,y,self.find(x),self.find(y),self.find(x) == self.find(y))'''
        return self.find(x) == self.find(y)

    def grouper(self):
        roots = [(x, self.find(x_par)) for x, x_par in self.parent.items()]
        root = operator.itemgetter(1)
        for _, group in itertools.groupby(sorted(roots, key=root), root):
            yield [x for x, _ in group]


n = onem()

tr = [[] for i in range(n)]
po = [0 for i in range(n)]

for i in range(n-1):
    a,b = m()
    tr[a-1].append(b-1)
    tr[b-1].append(a-1)

de = cl.deque([[0,-1,0]])
bl = 0
re = 0
while de:
    data = de.popleft()
    if data[2] == 0:
        po[data[0]] = 1
        re += 1
    else:
        po[data[0]] = 2
        bl += 1
    for i in range(len(tr[data[0]])):
        if tr[data[0]][i] != data[1]:
            de.append([tr[data[0]][i],data[0],data[2]+1])

tr = n // 3

b0 = cl.deque([(i+1)*3 for i in range(tr)])
b1 = cl.deque([(i)*3+1 for i in range(tr+(1 if n % 3 >= 1 else 0))])
b2 = cl.deque([(i)*3+2 for i in range(tr+(1 if n % 3 >= 2 else 0))])

if re <= tr:
    for i in range(n):
        if po[i] == 1:
            po[i] = b0.popleft()
        else:
            if len(b1) != 0:
                po[i] = b1.popleft()
            elif len(b2) != 0:
                po[i] = b2.popleft()
            else:
                po[i] = b0.popleft()

elif bl <= tr:
    for i in range(n):
        if po[i] == 2:
            po[i] = b0.popleft()
        else:
            if len(b1) != 0:
                po[i] = b1.popleft()
            elif len(b2) != 0:
                po[i] = b2.popleft()
            else:
                po[i] = b0.popleft()


else:
    for i in range(n):
        if po[i] == 1:
            if len(b1) != 0:
                po[i] = b1.popleft()
            else:
                po[i] = b0.popleft()
        else:
            if len(b2) != 0:
                po[i] = b2.popleft()
            else:
                po[i] = b0.popleft()



print(jo(po))





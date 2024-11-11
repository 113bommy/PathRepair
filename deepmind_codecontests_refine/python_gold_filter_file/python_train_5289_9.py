import sys
input = sys.stdin.readline
N = int(input())
XY = [tuple(map(int,input().split())) for i in range(N)]
XY.sort(key=lambda x:x[0])

ys = []
for _,y in XY:
    ys.append(y)
ys.sort()
yd = {y:i for i,y in enumerate(ys)}

class BinaryIndexedTree:
    def __init__(self,size):
        self.N = size
        self.bit = [0]*(size+1)
    def add(self,x,w): # 0-indexed
        x += 1
        while x <= self.N:
            self.bit[x] += w
            x += (x & -x)
    def _sum(self,x): # 1-indexed
        ret = 0
        while x > 0:
            ret += self.bit[x]
            x -= (x & -x)
        return ret
    def sum(self,l,r): # [l,r)
        return self._sum(r) - self._sum(l)
    def __str__(self): # for debug
        arr = [self.sum(i,i+1) for i in range(self.N)]
        return str(arr)

lbit = BinaryIndexedTree(N)
lu = []
ld = []
for i,(_,y) in enumerate(XY):
    d = lbit._sum(yd[y])
    u = i - d
    lu.append(u)
    ld.append(d)
    lbit.add(yd[y],1)

rbit = BinaryIndexedTree(N)
ru = []
rd = []
for i,(_,y) in enumerate(XY[::-1]):
    d = rbit._sum(yd[y])
    u = i - d
    ru.append(u)
    rd.append(d)
    rbit.add(yd[y],1)

MOD = 998244353
ans = 0
for a,b,c,d in zip(ld,lu,rd[::-1],ru[::-1]):
    pa,pb,pc,pd = pow(2,a,MOD),pow(2,b,MOD),pow(2,c,MOD),pow(2,d,MOD)
    ans += (pa-1) * (pd-1) * pb * pc
    ans += (pb-1) * (pc-1) * pa * pd
    ans -= (pa-1) * (pb-1) * (pc-1) * (pd-1)
    ans %= MOD
ans += N * pow(2,N-1,MOD)
ans %= MOD
print(ans)
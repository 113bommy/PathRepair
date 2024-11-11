import sys
input = sys.stdin.readline
n, q = map(int, input().split())
c = list(map(lambda x:int(x)-1, input().split()))
query = []
for i in range(q):
    l, r = map(int, input().split())
    query.append((i, l-1, r-1))

class BinaryIndexedTree():
    def __init__(self, n):
        self.n = n
        self.bit = [0]*n
    
    def add(self, i, w):
        x = i+1
        while x<=self.n:
            self.bit[x-1] += w
            x += x & -x
    
    def sum_(self, i):
        ret = 0
        x = i+1
        while x>0:
            ret += self.bit[x-1]
            x -= x & -x
        return ret

bit = BinaryIndexedTree(n+1)
query.sort(key=lambda x:x[2])
last = [None]*n
ans = [None]*q
nr = -1
for idx, l, r in query:
    for cr in range(nr+1, r+1):
        if last[c[cr]] is not None:
            bit.add(last[c[cr]]+1, -1)
        last[c[cr]] = cr
        bit.add(cr+1, 1)
    nr = r
    ans[idx] = bit.sum_(r+1) - bit.sum_(l)
for i in ans:
    print(i)
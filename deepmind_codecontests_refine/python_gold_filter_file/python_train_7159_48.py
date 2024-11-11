import sys
input = sys.stdin.readline
from collections import *

class BIT:
    def __init__(self, n):
        self.n = n
        self.bit = [0]*(n+1)
    
    def add(self, i, x):
        i += 1
        
        while i<=self.n:
            self.bit[i] += x
            i += i&(-i)

    def acc(self, i):
        s = 0
        
        while i>0:
            s += self.bit[i]
            i -= i&(-i)
        
        return s

N, Q = map(int, input().split())
c = list(map(int, input().split()))
prev = [-1]*N
ys = defaultdict(list)

for i in range(N):
    if prev[c[i]-1]!=-1:
        ys[prev[c[i]-1]].append(i)
    
    prev[c[i]-1] = i

que = defaultdict(list)

for i in range(Q):
    l, r = map(int, input().split())
    que[l-1].append((i, r-1))
    
idx = 0
bit = BIT(N)
ans = [-1]*Q

for x in range(N-1, -1, -1):
    for y in ys[x]:
        bit.add(y, 1)
    
    for i, r in que[x]:
        ans[i] = r-x+1-bit.acc(r+1)

for ans_i in ans:
    print(ans_i)
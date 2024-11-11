# -*- coding: utf-8 -*-
import sys 
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

MOD = 998244353

class BIT2:
    def __init__(self, N):
        self.N = (N+1)
        self.data0 = [0] * (N+1)
        self.data1 = [0] * (N+1)
        
    def _add(self, data, k, x):
        while k < self.N: #k <= Nと同義
            data[k] += x
            k += k & -k

    def _sum(self, data, k):
        s = 0
        while k:
            s += data[k]
            k -= k & -k
        return s

    def add(self, l, r, x):
        self._add(self.data0, l, -x*(l-1))
        self._add(self.data0, r, x*(r-1))
        self._add(self.data1, l, x)
        self._add(self.data1, r, -x)

    def sum(self, l, r):
        return self._sum(self.data1, r-1) * (r-1) + self._sum(self.data0, r-1) \
                - self._sum(self.data1, l-1) * (l-1) - self._sum(self.data0, l-1) #改行

N, Q = map(int, readline().split())
bit1 = BIT2(N)
bit1.add(1,N+1,N-2)
bit2 = BIT2(N)
bit2.add(1,N+1,N-2)
total = (N-2)**2

right = N
low = N
cnt = 0
for _ in range(Q):
    cmd,t = map(int,readline().split())
    if cmd == 1:
        tmp = bit1.sum(t,t+1)
        cnt += tmp
        bit1.add(t,t+1,-tmp)
        if t < right:
            bit2.add(1,low,t-right) 
            right = t
    else:
        tmp = bit2.sum(t,t+1)
        cnt += tmp
        bit2.add(t,t+1,-tmp)
        if t < low:
            bit1.add(1,right,t-low)  
            low = t

ans = total - cnt
print(ans) 
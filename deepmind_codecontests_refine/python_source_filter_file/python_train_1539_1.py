import sys, math
from collections import defaultdict, deque, Counter
from bisect import bisect_left, bisect_right
from itertools import combinations, permutations, product
from heapq import heappush, heappop
from functools import lru_cache
input = sys.stdin.readline
rs = lambda: input().strip()
ri = lambda: int(input())
rl = lambda: list(map(int, input().split()))
mat = lambda x, y, v: [[v]*y for _ in range(x)]
ten = lambda x, y, z, v: [mat(y, z, v) for _ in range(x)]
mod = 1000000007
sys.setrecursionlimit(1000000)

class BIT:
    def __init__(self, n):
        self.n = n
        self.nums = [0] * (n+1)
        
    def add(self, i, x):
        n, nums = self.n, self.nums
        i += 1
        while i <= n:
            nums[i] += x
            i += i & -i
    
    def sum(self, i):
        nums = self.nums
        s = 0
        i += 1
        while i:
            s += nums[i]
            i -= i & -i
        return s
    
    def search(self, x):
        # minimum index i such that x <= self.sum(i)
        n, nums = self.n, self.nums
        s, p = 0, 0
        for i in range(n.bit_length(), -1, -1):
            np = p + (1<<i)
            if np <= n and s+nums[np] < x:
                s += nums[np]
                p = np
        return p

class MultiSet:
    def __init__(self, n):
        self.bit = BIT(n)

    def insert(self, key):
        self.bit.add(key, 1)

    def erase(self, key):
        self.bit.add(key, -1)

    def top(self, i=0):
        # i-th smallest element
        return self.bit.search(i+1)

    def size(self):
        return self.bit.sum(self.bit.n-1)

    def count(self, key):
        # number of keys
        return self.bit.sum(key)-self.bit.sum(key-1)

    def lower_bound(self, key):
        # minimum key k no less than key (key <= k)
        return self.bit.search(self.bit.sum(key-1)+1)

    def upper_bound(self, key):
        # minimum key k greater than key (key < k)
        return self.bit.search(self.bit.sum(key)+1)

    def debug(self):
        vals = []
        for i in range(self.bit.n):
            key = self.top(i)
            if key == self.bit.n: break
            vals.append(key)
        print(vals)

class Map(MultiSet):
    def __init__(self, n):
        super().__init__(n)
        self.data = {}

    def __getitem__(self, key):
        return self.data[key]

    def __setitem__(self, key, val):
        self.insert(key, val)

    def insert(self, key, val=None):
        if key not in self.data:
            super().insert(key)
        self.data[key] = val

    def erase(self, key):
        if key in self.data:
            super().erase(key)
            del self.data[key]

    def debug(self):
        vals = []
        for i in range(self.bit.n):
            key = self.top(i)
            if key == self.bit.n: break
            vals.append((key, self[key]))
        print(vals)

H, W = rl()
walls = []
for i in range(H):
    a, b = rl()
    a, b = a-1, b-1
    walls.append((a,b))

mp = Map(W)
for i in range(W):
    mp[i] = i
ms = MultiSet(W)
for i in range(W):
    ms.insert(0)

for idx, (a, b) in enumerate(walls):
    i = mp.lower_bound(a)
    r = -1
    #print('mp:', end='')
    #mp.debug()
    #print('ms:', end='')
    #ms.debug()
    while i < W and i <= b:
        r = max(r, mp[i])
        ms.erase(i-mp[i])
        mp.erase(i)
        i = mp.lower_bound(i)
    if r != -1 and b+1 < W:
        ms.insert(b+1-r)
        mp[b+1] = r
    ans = -1
    if ms.size() > 0:
        ans = ms.top() + idx + 1
    print(ans)


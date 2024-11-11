''' ===============================
    -- @uthor : Kaleab Asfaw
    -- Handle : kaleabasfaw2010
    -- Bio    : High-School Student
    ==============================='''

# Fast IO
import sys
import os
from io import BytesIO, IOBase
from time import time
BUFSIZE = 8192
class FastIO(IOBase):
    newlines = 0
    def __init__(self, file): self._fd = file.fileno(); self.buffer = BytesIO(); self.writable = "x" in file.mode or "r" not in file.mode; self.write = self.buffer.write if self.writable else None
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b: break
            ptr = self.buffer.tell(); self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0; return self.buffer.read()
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE)); self.newlines = b.count(b"\n") + (not b); ptr = self.buffer.tell(); self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1; return self.buffer.readline()
    def flush(self):
        if self.writable: os.write(self._fd, self.buffer.getvalue()); self.buffer.truncate(0), self.buffer.seek(0)
class IOWrapper(IOBase):
    def __init__(self, file): self.buffer = FastIO(file); self.flush = self.buffer.flush; self.writable = self.buffer.writable; self.write = lambda s: self.buffer.write(s.encode("ascii")); self.read = lambda: self.buffer.read().decode("ascii"); self.readline = lambda: self.buffer.readline().decode("ascii")
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout); input = lambda: sys.stdin.readline().rstrip("\r\n")
# Others
# from math import floor, ceil, gcd
# from decimal import Decimal as d
mod = 10**9+7
def lcm(x, y): return (x * y) / (gcd(x, y))
def fact(x, mod=mod):
    ans = 1
    for i in range(1, x+1): ans = (ans * i) % mod
    return ans
def arr2D(n, m, default=0): return [[default for j in range(m)] for i in range(n)]
def arr3D(n, m, r, default=0): return [[[default for k in range(r)] for j in range(m)] for i in range(n)]
def sortDictV(x): return {k: v for k, v in sorted(x.items(), key = lambda item : item[1])}
class DSU:
    def __init__(self, length): self.length = length; self.parent = [-1] * self.length  # O(log(n))
    def getParent(self, node, start):  # O(log(n))
        if node >= self.length: return False
        if self.parent[node] < 0:
            if start != node: self.parent[start] = node
            return node
        return self.getParent(self.parent[node], start)
    def union(self, node1, node2):  # O(log(n))
        parent1 = self.getParent(node1, node1); parent2 = self.getParent(node2, node2)
        if parent1 == parent2: return False
        elif self.parent[parent1] <= self.parent[parent2]: self.parent[parent1] += self.parent[parent2]; self.parent[parent2] = parent1
        else: self.parent[parent2] += self.parent[parent1]; self.parent[parent1] = parent2
        return True
    def getCount(self, node):  return -self.parent[self.getParent(node, node)] # O(log(n))

def exact(num):
    if abs(num - round(num)) <= 10**(-9):return round(num)
    return num

import math 
def primeFactors(n):
    factors = []
    while n % 2 == 0: 
        factors.append(2) 
        n = n / 2
    for i in range(3,int(math.sqrt(n))+1,2): 
        while n % i== 0: 
            factors.append(i) 
            n = n / i 
    if n > 2: 
        factors.append(n)
    return factors


def solve(n):
    if n == 1:
        print(1, 0)
        return
    factors = primeFactors(n)
    times = []

    factMap = {}
    
    for i in factors:
        if factMap.get(i) == None:
            factMap[i] = 1
        else:
            factMap[i] += 1

    maxx = 0
    for i in factMap:
        maxx = max(maxx, factMap[i])

    minn = 1
    for i in factMap:
        minn *= i

    if maxx % 2 :
        maxx += 1
    
    # maxx = 2 ** math.ceil(math.log2(maxxx))
    # times = 0
    # while maxx % 2 == 0:
    #     times += 1
    #     maxx //= 2
    times = math.ceil(math.log2(maxx))
    add = 1
    if minn ** (2 ** times) == n: add = 0
    if minn == n:
        print(minn, 0)
    else:
        print(int(minn), math.ceil(math.log2(maxx)) + add)




n = int(input())
solve(n)
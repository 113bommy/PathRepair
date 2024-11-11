# Date [ 2020-09-08 00:35:49 ]
# Problem [ j.py ]
# Author Koki_tkg

import sys
# import math
# import bisect
# import numpy as np
# from decimal import Decimal
# from numba import njit, i8, u1, b1 #JIT compiler
# from itertools import combinations, product
# from collections import Counter, deque, defaultdict

# sys.setrecursionlimit(10 ** 6)
MOD = 10 ** 9 + 7
INF = 10 ** 9
PI = 3.14159265358979323846

def read_str():      return sys.stdin.readline().strip()
def read_int():      return int(sys.stdin.readline().strip())
def read_ints():     return map(int, sys.stdin.readline().strip().split())
def read_ints2(x):   return map(lambda num: int(num) - x, sys.stdin.readline().strip().split())
def read_str_list(): return list(sys.stdin.readline().strip().split())
def read_int_list(): return list(map(int, sys.stdin.readline().strip().split()))
def GCD(a: int, b: int) -> int: return b if a%b==0 else GCD(b, a%b)
def LCM(a: int, b: int) -> int: return (a * b) // GCD(a, b)

class SegmentTree:
    def __init__(self, array, function, identify):
        self.length = len(array)
        self.func, self.ide_ele = function, identify

        self.size = 1 << (self.length-1).bit_length()
        self.data = [self.ide_ele] * 2*self.size
        # set
        for i in range(self.length):
            self.data[self.size + i] = array[i]
        # build
        for i in range(self.size-1, 0, -1):
            self.data[i] = self.func(self.data[2*i], self.data[2*i + 1])

    def update(self, idx, x):
        idx += self.size
        self.data[idx] = x
        while idx > 0:
            idx >>= 1
            self.data[idx] = self.func(self.data[2*idx], self.data[2*idx + 1])
 
    def query(self, l, r):
        l += self.size; r += self.size+1
        l_ret = r_ret = self.ide_ele
        while l < r:
            if l & 1:
                l_ret = self.func(l_ret, self.data[l])
                l += 1
            if r & 1:
                r -= 1
                r_ret = self.func(self.data[r], r_ret)
            l >>= 1; r >>= 1
        return self.func(l_ret, r_ret)

    def get(self, idx):
        return self.data[idx+self.size]

def Main():
    n, q = read_ints()
    a = read_int_list()
    seg = SegmentTree(a, max, -float('inf'))
    for _ in range(q):
        t, x, v = read_ints()
        if t == 1:
            seg.update(~-x, v)
        elif t == 2:
            print(seg.query(~-x, v))
        else:
            l = x - 1; r = n + 1
            while r - l > 1:
                mid = (l + r) // 2
                if seg.query(~-x, ~-mid) >= v:
                    r = mid
                else:
                    l = mid
            print(r)

if __name__ == '__main__':
    Main()
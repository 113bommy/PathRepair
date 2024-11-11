from cmath import rect
import sys
import math
from functools import reduce

class SegmentTree():
    def __init__(self, L, function = lambda x,y: x+y):
        self.function = function
        N = self.size = len(L)
        M = 1 << N.bit_length()
        self.margin = 2*M - N
        self.L = [None for i in range(self.margin)] + L
        for i in range(M-1, 0, -1):
            x, y = self.L[i<<1], self.L[i<<1|1]
            self.L[i] = None if x is None or y is None else function(x, y)
    def modify(self, pos, value):
        p = pos + self.margin
        self.L[p] = value 
        while p > 1:
            x, y = self.L[p], self.L[p^1]
            if p&1: x, y = y, x
            self.L[p>>1] = None if x is None or y is None else self.function(x, y)
            p>>=1
    def query(self, left, right):
        l, r = left + self.margin, right + self.margin
        stack = []
        void = True
        while l < r:
            if l&1:
                if void:
                    result = self.L[l]
                    void = False
                else:
                    result = self.function(result, self.L[l])
                l+=1
            if r&1:
                r-=1
                stack.append(self.L[r])
            l>>=1
            r>>=1
        init = stack.pop() if void else result
        return reduce(self.function, reversed(stack), init)

def degrect(r, phi):
    return rect(r, math.radians(phi))

def vsum(u, v): #u = (x + y*1j, phi)
    return (u[0] + v[0]*degrect(1, u[1]), (u[1] + v[1])%360)

def solve(f):
    n, m = [int(x) for x in f.readline().split()]
    segments = [[1,0] for i in range(n)]
    arm = SegmentTree([(1,0) for i in range(n)], vsum)
    for line in f:
        q, i, a = [int(x) for x in line.split()]
        if q == 1:
            segments[i-1][0] += a
        else:
            segments[i-1][1] -= a
        arm.modify(i-1, (degrect(segments[i-1][0], segments[i-1][1]), segments[i-1][1]))
        query = arm.query(0,n)[0]
        sys.stdout.write(str(query.real) + ' ' + str(query.imag) + '\n')

solve(sys.stdin)
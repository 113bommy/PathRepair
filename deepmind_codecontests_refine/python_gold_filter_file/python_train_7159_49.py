#!usr/bin/env python3
import sys
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LIR(n):
    return [LI() for i in range(n)]

def solve():
    def add(i,x):
        while i < len(bit):
            bit[i] += x
            i += i&-i
    def sum_(i):
        res = 0
        while i > 0:
            res += bit[i]
            i -= i&-i
        return res
    n,Q = LI()
    c = LI()
    c = [0]+c
    q = [[i,LI()] for i in range(Q)]
    q.sort(key = lambda x:x[1][1])
    bit = [0]*(n+2)
    i = 1
    p = [None]*(n+1)
    ans = [0]*Q
    s = 0
    for ind,(l, r) in q:
        l -= 1
        while i <= r:
            ci = c[i]
            j = p[ci]
            if j is not None:
                add(j,1)
            else:
                s += 1
            p[ci] = i
            i += 1
        ans[ind] = s-l+sum_(l)
    for i in ans:
        print(i)
    return

#Solve
if __name__ == "__main__":
    solve()

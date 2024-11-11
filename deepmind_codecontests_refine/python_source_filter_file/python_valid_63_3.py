import sys
import math
import bisect
from sys import stdin, stdout
from math import gcd, floor, sqrt, log
from collections import defaultdict as dd
from bisect import bisect_left as bl, bisect_right as br
from collections import Counter
from collections import defaultdict as dd
from collections import defaultdict as dd

# sys.setrecursionlimit(100000000)

flush = lambda: stdout.flush()
stdstr = lambda: stdin.readline()
stdint = lambda: int(stdin.readline())
stdpr = lambda x: stdout.write(str(x))
stdmap = lambda: map(int, stdstr().split())
stdarr = lambda: list(map(int, stdstr().split()))

mod = 1000000007

class DSU:
    def __init__(self, n):
        self.n = n
        self.size = [1] * (n)
        self.parent = list(range(n))

    def union(self, a, b):
        pa = self.find(a)
        pb = self.find(b)

        if (pa != pb):
            if (self.size[pa] < self.size[pb]):
                pa, pb = pb, pa

            self.parent[b] = a
            self.size[a] += self.size[b]

    def find(self, a):
        temp = a

        while (self.parent[a] != a):
            a = self.parent[a]
        while (temp != a):
            self.parent[temp], temp = a, self.parent[temp]

        return a


n,m1,m2 = stdmap()

d1 = DSU(n)
d2 = DSU(n)

for i in range(m1):
    a,b = stdmap()
    a-= 1
    b-=1

    d1.union(a,b)

for j in range(m2):
    a, b = stdmap()
    a-=1
    b-=1
    d2.union(a,b)

res = []
for i in range(n):
    for j in range(i+1, n):
        c1 = d1.find(i)
        c2 = d1.find(j)

        x1 = d2.find(i)
        x2 = d2.find(j)

        if(c1 == c2 or x2 == x1):
            continue
        else:
            res.append([i+1,j+1])

            d1.union(i,j)
            d2.union(i,j)

print(len(res))
for j in res:
    print(*j)


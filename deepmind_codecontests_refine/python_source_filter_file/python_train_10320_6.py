from sys import stdout, stdin, setrecursionlimit
from io import BytesIO, IOBase
from collections import *
from itertools import *
from random import *
from bisect import *
from string import *
from queue import *
from heapq import *
from math import *
from re import *
from os import *

####################################---fast-input-output----#########################################


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = read(self._fd, max(fstat(self._fd).st_size, 8192))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = read(self._fd, max(fstat(self._fd).st_size, 8192))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


stdin, stdout = IOWrapper(stdin), IOWrapper(stdout)
def input(): return stdin.readline().strip()
def fast(): return stdin.readline().strip()
def zzz(): return [int(i) for i in fast().split()]


z, zz = fast, lambda: (map(int, z().split()))
szz, graph, mod, szzz = lambda: sorted(
    zz()), {}, 10**9 + 7, lambda: sorted(zzz())


def lcd(xnum1, xnum2): return (xnum1 * xnum2 // gcd(xnum1, xnum2))
def output(answer, end='\n'): stdout.write(str(answer) + end)


dx = [-1, 1, 0, 0, 1, -1, 1, -1]
dy = [0, 0, 1, -1, 1, -1, -1, 1]


#################################################---Some Rule For Me To Follow---#################################
"""
    --instants of Reading problem continuously try to understand them.

    --If you Know some-one , Then you probably don't know him !

    --Try & again try

"""
##################################################---START-CODING---###############################################



if randint(1,20)==6:
    print("hacked")
    exit()

n=int(z())

ans=[0]*(n+1)
for _ in range(n):
    x,y=zzz()
    ans[_+1]=[x,y]
if n<=3:
    print(*[i for i in range(1,n+1)])
    exit()
new=[0]*n
new[0]=1
for i in range(1,n):
    l,r=ans[new[i-1]]
    new[i]=l if r in ans[l] else r
print(*new) 


# n = int(input())
# if n is 3:
#     print(1,2,3)
#     exit(0)
# a=[0]*(n+1)
# for i in range(n):
#     a[i+1] = [ int(t) for t in input().split() ]
# r = [0]*n
# r[0]=1
# for i in range(1, n):
#     p, q = a[r[i - 1]]
#     r[i] = p if q in a[p] else q
# print(*r)

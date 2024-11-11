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
graph, mod, szzz =  {}, 10**9 + 7, lambda: sorted(zzz())
def getStr(): return input()
def getInt(): return int(input())
def listStr(): return list(input())
def getStrs(): return input().split()
def isInt(s): return '0' <= s[0] <= '9'
def input(): return stdin.readline().strip()
def zzz(): return [int(i) for i in input().split()]
def output(answer, end='\n'): stdout.write(str(answer) + end)
def lcd(xnum1, xnum2): return (xnum1 * xnum2 // gcd(xnum1, xnum2))


dx = [-1, 1, 0, 0, 1, -1, 1, -1]
dy = [0, 0, 1, -1, 1, -1, -1, 1]
daysInMounth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]


#################################################---Some Rule For Me To Follow---#################################
"""
    --instants of Reading problem continuously try to understand them.

    --If you Know some-one , Then you probably don't know him !

    --Try & again try, maybe you're just one statement away!


"""
##################################################---START-CODING---###############################################




# s = input().strip()

# n = len(s)

# class segTree:
#     def __init__(self):
#         self.a = [0]*(2*n)
#         self.b = [0]*(2*n)
#         self.c = [0]*(2*n)
    
#     def build(self, arr):
#         for i in range(n):
#             self.a[i+n] = 0
#             self.b[i+n] = 1 if arr[i] == '(' else 0
#             self.c[i+n] = 1 if arr[i] == ')' else 0
#         for i in range(n-1,0,-1):
#             to_match = min(self.b[i << 1],self.c[i << 1 | 1])
#             self.a[i] = self.a[i << 1] + self.a[i << 1 | 1] + 2*to_match
#             self.b[i] = self.b[i << 1] + self.b[i << 1 | 1] - to_match
#             self.c[i] = self.c[i << 1] + self.c[i << 1 | 1] - to_match
#     def query(self, l, r):  
#         left = []
#         right = []
#         l += n 
#         r += n 
#         while l <= r: 
#             if (l & 1): 
#                 left.append((self.a[l],self.b[l],self.c[l]))
#                 l += 1
#             if not (r & 1): 
#                 right.append((self.a[r],self.b[r],self.c[r]))
#                 r -= 1 
#             l >>= 1 
#             r >>= 1
#         a1 = b1 = c1 = 0
#         for a2, b2, c2 in left + right[::-1]:
#             to_match = min(b1,c2)
#             a1 += a2 + 2*to_match
#             b1 += b2 - to_match
#             c1 += c2 - to_match
#         return a1
# tree = segTree()
# tree.build(s)
# for m in range(getInt()):
#     l, r = zzz()
#     l -= 1
#     r -= 1
#     print(tree.query(l,r))

num = 1
# num = getInt()


for i in range(num):
    m,n=zzz()
    for i in range(m):
        s=getStr()
        print ("".join("-BW"[((i+j)%2+1)*(s[j]!='-')]for j in range(n)))
    # left=abs(x1-x)
    # right=abs(x2-x)
    # up=abs(y1-y)
    # down=abs(y2-y)
    # mnLR=min(a,b)
    # mnUD=min(c,d)
    # a-=mnLR
    # b-=mnLR
    # c-=mnUD
    # d-=mnUD

    # if x1<=x-a+b <=x2 and y1<=y-c+d<=y2  and (x1<x2 or a+b==0) and(y1<y2 or c+d==0):
    #     print('Yes')
    # else:
    #     print('No')
# for _ in range(int(input())):
#     l,r,d,u=map(int,input().split())
#     x,y,ll,dd,rr,uu=map(int,input().split())
#     m=(r-l)+x
#     n=(u-d)+y
#     if ll<=m and m<=rr and dd<=n and n<=uu:
#         if l+r!=0 and ll==rr==x or u+d!=0 and uu==dd==y:
#             print('No')
#         else:print('Yes')
#     else:
#         print('No')
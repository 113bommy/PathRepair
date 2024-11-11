"""
#If FastIO not needed, use this and don't forget to strip
#import sys, math
#input = sys.stdin.readline
"""

import os, sys, heapq as h, time
from io import BytesIO, IOBase
from types import GeneratorType
from bisect import bisect_left, bisect_right
from collections import defaultdict as dd, deque as dq, Counter as dc
import math, string
BUFSIZE = 8192

class FastIO(IOBase):
    newlines = 0
    def __init__(self, file):
        import os
        self.os = os
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
    def read(self):
        while True:
            b = self.os.read(self._fd, max(self.os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
    def readline(self):
        while self.newlines == 0:
            b = self.os.read(self._fd, max(self.os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
    def flush(self):
        if self.writable:
            self.os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")

sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

#start_time = time.time()

def getInt(): return int(input())
def getStrs(): return input().split()
def getInts(): return list(map(int,input().split()))
def getStr(): return input()
def listStr(): return list(input())
def getMat(n): return [getInts() for _ in range(n)]
def isInt(s): return '0' <= s[0] <= '9'

MOD = 10**9 + 7 

"""
Let's find the first number that is in the wrong place. Keep swapping the 

I need to partition the cycles, and then make sure I link each cycle
"""


def solve():
    N = getInt()
    A = [0]+getInts()
    used = [False]*(N+1)
    ans = []
    prev_ = -1
    def swap_(i,j):
        ans.append((i,j))
        A[i], A[j] = -A[j], -A[i]
        return
    """
    [2,3,1,5,6,4]
    swap_(1,4)
    [-5,3,1,-2,6,4]
    [-6,3,1,-2,5,4]
    [-4,3,1,-2,5,6]
    [-4,2,1,-3,5,6]
    [-4,2,3,-1,5,6]
    idx = 1
    eg A[-A[idx]] = 6, so swap 1 and 5
    once we hit a negative number, swap to that index
    """
    def join_cycles(i,j):
        swap_(i,j)
        idx = i
        while A[-A[idx]] > 0: swap_(idx,-A[idx]) #A[idx] is negative because we swapped i with j (this is the first 'part' of the cycle, up to the artificially induced element
        idx = -A[idx]
        while A[-A[idx]] > 0: swap_(idx,-A[idx]) #this is the second part of the cycle
        swap_(idx,-A[idx]) # the final two elements
    for i in range(1,N+1):
        if A[i] == i: used[i] = True
        if used[i]: continue
        idx = i
        while True:
            used[idx] = True
            idx = A[idx]
            if idx == i: break # cycle has ended
        if prev_ == -1:
            prev_ = i # we don't have a cycle to join it with yet
        else:
            join_cycles(prev_,i) # we do have a cycle to join it with
            prev_ = -1
    if prev_ > -1: # we have one remaining unjoined cycle
        j = 1
        while j <= N and A[j] != j: j += 1
        if j <= N:
            # if possible join the cycle with a correct element - this only adds one extra move. This treats the swapping of 2 case.
            join_cycles(prev_,j)
        else:
            # if this isn't possible (eg [2,3,1]) then breaking any pair will suffice, eg [-1,3,-2]. Then we join with any other element in the permutation.
            i0, i1 = prev_, A[prev_]
            swap_(i0,i1)
            j = 1
            while j in [i0,i1]: j += 1 # make sure j is different to the elements we just swapped
            join_cycles(i0,j)
    print(len(ans))
    for a, b in ans: print(a,b)
    return
        
#for _ in range(getInt()):
#print(solve())
solve()

#print(time.time()-start_time)
"""
#If FastIO not needed, use this and don't forget to strip
#import sys, math
#input = sys.stdin.readline
"""

import os
import sys
from io import BytesIO, IOBase
import heapq as h 
from bisect import bisect_left, bisect_right
import time

from types import GeneratorType
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

from collections import defaultdict as dd, deque as dq, Counter as dc
import string
from math import sqrt

#start_time = time.time()

def getInts():
    return [int(s) for s in input().split()]

def getInt():
    return int(input())

def getStrs():
    return [s for s in input().split()]

def getStr():
    return input()

def listStr():
    return list(input())

def getMat(n):
    return [getInts() for _ in range(n)]

def isInt(s):
    return '0' <= s[0] <= '9'

MOD = 10**9 + 7 

"""
S = U T + 0.5 A T^2
V^2 = U^2 + 2 A S
V = U + A T
S = V T - 0.5 A T^2

If V < W:
    linearly accelerate to V, then cruise to the end

If V >= W:
    If we can get to speed W in distance <= D:
        cruise to W, then reach the max speed such that we can still decelerate to W. Then post camera, accelerate to V and then cruise
    Else:
        linearly accelerate all the way to speed V, then cruise to the end

2*W*T + A * T^2 - 2*rem_dist = 0
"""

def t_from_s_a_u(s,a,u):
    return (-2*u + sqrt(4*u*u + 8*s*a))/(2*a)
    

def solve():
    A, V = getInts()
    L, D, W = getInts()
    if V <= W or W**2 >= 2*A*D: # this renders W irrelevant
        #can we get to speed V before distance L?
        if V**2 >= 2*A*L:
            return sqrt(2*L/A)
        else:
            dist_1 = (V**2)/(2*A)
            T1 = 2*dist_1/V
            dist_2 = L - dist_1
            T2 = dist_2/V
            return T1+T2
    else:
        #V > W, and we reach W in time
        dist_1 = (W**2)/(2*A)
        T1 = sqrt(2*dist_1/A)
        rem_dist = D - dist_1
        dist_A = (V**2 - W**2)/(2*A)
        if 2*dist_A >= rem_dist:
            #accelerate then decelerate the whole time. Accelerate for rem_dist/2, decelerate for rem_dist/2
            TA = 2*t_from_s_a_u(rem_dist/2,A,W)
        else:
            TA1 = 2*(V-W)/A
            SA1 = (V+W)*(V-W)/A
            SA2 = rem_dist - SA1
            TA2 = SA2/V
            TA = TA1 + TA2
        T1 += TA
        #now we are at speed W again, so we accelerate to V and then cruise
        if V**2 - W**2 >= 2*A*(L-D):
            #accelerate linearly from W to V
            #print(T1,t_from_s_a_u(L-D,A,W))
            return T1 + t_from_s_a_u(L-D,A,W)
        else:
            dist_2 = (V**2 - W**2)/(2*A)
            T2 = 2*dist_2/(V+W)
            dist_3 = L - D - dist_2
            T3 = dist_3/V
            #print(T1,T2,T3)
            return T1+T2+T3
    return
    
#for _ in range(getInt()):
print(solve())
#solve()


#print(time.time()-start_time)
import os
import sys
from io import BytesIO, IOBase
 
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
 
import time
start_time = time.time()

import collections as col
import math
from functools import reduce

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



"""
a1 a2 a3 a4 a5 a6
b1 b2 b3 b4 b5 b6
c1 c2 c3 c4 c5 c6
d1 d2 d3 d4 d5 d6

M and N are small!

Candidate strings:
    O(26*M) possible strings (260)
    For each of these, count the differences with each of the other strings.
    If all OK, output
    Otherwise, move on.
    If no string, fail

"""
def diff(s1,s2):
    count = 0
    for i in range(len(s1)):
        if s1[i] != s2[i]:
            count +=1 
    return count

def works(s1,list_s):
    for S in list_s:
        if diff(S,s1) > 1:
            return False
    return True

def solve():
    N, M = getInts()

    SS = []
    for n in range(N):
        SS.append(listStr())
    if N == 1:
        return ''.join(SS[0])
    if M == 1:
        return 'a'
    #M > 1, N > 1
    #change position i
    for i in range(M):
        for j in range(26):
            tmp = SS[0]
            tmp[i] = chr(ord('a')+j)
            if works(tmp,SS[1:]):
                return ''.join(tmp)
    return -1
    
    
for _ in range(getInt()):    
    print(solve())

 

#Code by Sounak, IIESTS
#------------------------------warmup----------------------------

import os
import sys
import math
from io import BytesIO, IOBase
from fractions import Fraction
import collections
from itertools import permutations
from collections import defaultdict
from collections import deque
import threading



threading.stack_size(10**8)
sys.setrecursionlimit(300000)

BUFSIZE = 8192
 
 
class FastIO(IOBase):
    newlines = 0
    
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
     
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
 
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
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

#-------------------game starts now-----------------------------------------------------
#mod = 9223372036854775807  
def main():
    for ik in range(int(input())):
        n=int(input())
        graph=defaultdict(list)
        visited = [False] * n
        sub=[0]*n
        cen=[]
        def dfssub(v):
            visited[v] = True
            c = 1
            for i in graph[v]:
                if visited[i] == False:
                    c += dfssub(i)
            sub[v]=c
            return c
        def dfs(v):
            visited[v] = True
            f=0
            for i in graph[v]:
                if visited[i] == False:
                    dfs(i)
                    if sub[i]>n//2:
                        f=1
            if n-sub[v]>n//2:
                f=1
            if f==0:
                cen.append(v)
        for i in range(n-1):
            a,b=map(int,input().split())
            graph[a-1].append(b-1)
            graph[b-1].append(a-1)
        dfssub(0)
        visited=[False]*n
        dfs(0)
        #print(cen,sub)
        if len(cen)==1:
            print(1,graph[0][0]+1)
            print(1, graph[0][0] + 1)
            continue
        for i in graph[cen[0]]:
            if cen[1]!=i:
                print(cen[0]+1,i+1)
                print(cen[1] + 1, i + 1)
                break
t = threading.Thread(target=main)
t.start()
t.join()
   
#from collections import OrderedDict
from collections import defaultdict
#from functools import reduce
#from itertools import groupby
#sys.setrecursionlimit(10**6)
#from itertools import accumulate
from collections import Counter
import math
import sys
import os
from io import BytesIO, IOBase
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
'''
from threading import stack_size,Thread
sys.setrecursionlimit(10**6)
stack_size(10**8)
'''
def listt():
    return [int(i) for i in input().split()]
       
parent={}
rank={}
l=[]
parent={}
def find(x):
    lii=[]
    while parent[x]!=x:
        lii.append(x)
        x=parent[x]
    for i in lii:
        parent[i]=x
    return x 
def union(a,b):
    a=find(a)
    b=find(b)
    if a==b:
        return
    if rank[a]>rank[b]:
        parent[b]=a
        rank[a]+=rank[b]
    else:
        parent[a]=b
        rank[b]+=rank[a]
           
n,k=map(int,input().split())
for i in range(1,n+1):
    parent[i]=i
    rank[i]=1
for i in range(n-1):
        u,v,w=map(int,input().split()) 
        if w==0:
            union(u,v)
s=set()            
for i in range(1,n+1):
    s.add(parent[i])
su=0    
for i in s:   
    su+=rank[i]**k
print((n**k-su)%1000000007)    
                        
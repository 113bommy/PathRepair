#------------------------template--------------------------#
import os
import sys
from math import *
from collections import *
# from fractions import *
# from functools import *
from heapq import *
from bisect import *
from io import BytesIO, IOBase
def vsInput():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
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
ALPHA='abcdefghijklmnopqrstuvwxyz'
M = 998244353
EPS = 1e-6
def Ceil(a,b): return a//b+int(a%b>0)
def value():return tuple(map(int,input().split()))
def array():return [int(i) for i in input().split()]
def Int():return int(input())
def Str():return input()
def arrayS():return [i for i in input().split()]


#-------------------------code---------------------------#
# vsInput()

def forward(x,y,ch):
    if(ch == 'R'): x += 1
    elif(ch == 'L'): x -= 1
    elif(ch == 'U'): y += 1
    elif(ch == 'D'): y -= 1
    return x,y

def backward(x,y,ch):
    if(ch == 'R'): x -= 1
    elif(ch == 'L'): x += 1
    elif(ch == 'U'): y -= 1
    elif(ch == 'D'): y += 1
    return x,y


def ok(sz):
    
    x = 0
    y = 0
    l = 0
    
    if(sz == 0):
        for i in range(n): x,y = forward(x,y,s[i])
        return x,y == need_x,need_y
    
    for i in range(sz - 1,n):
        x,y = forward(x,y,s[i])
    
    for r in range(sz - 1,n):
        x,y = backward(x,y,s[r])
        steps_required = abs(need_x - x) + abs(need_y - y)
        if(steps_required <= sz and (sz - steps_required)%2 == 0): return True
        
        x,y = forward(x,y,s[l])
        l += 1
        
    return False
        


for _ in range(1):

    n = Int()
    s = input()
    n = len(s)
    need_x,need_y = value()
    
    l = 0
    r = n
    ans = -1
    
    while(l <= r):
        
        m = l + (r - l)//2
        if(ok(m)):
            ans = m
            r = m - 1
        else:
            l = m + 1
            
    
    print(ans)
            
        
    
                
            
    
        
        
        
    
    
    
        
        
        
    

            
            
    
            
    
    
            
        
        
    


    
        



    




















    





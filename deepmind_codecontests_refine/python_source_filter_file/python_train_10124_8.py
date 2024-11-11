from collections import deque
from collections import OrderedDict
import math

import sys
import os
from io import BytesIO
import threading
import bisect


import heapq

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


     
        
#sys.stdin = open("F:\PY\\test.txt", "r")
#input = sys.stdin.readline        


#import io, sys, atexit, os
#sys.stdout = io.BytesIO()
#atexit.register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))
#sys.stdin = io.BytesIO(sys.stdin.read())
#raw_input = lambda: sys.stdin.readline().rstrip()




def fun(str1, f1,f2,f3, start, goto, step):
   for i in range(start, goto, step):
       #print(i)
       if str1[i]=='1':
            f1[i]=i
            f2[i]=f2[i-step]
            f3[i]=f3[i-step]
       elif str1[i]=='2':
            f1[i]=f1[i-step]
            f2[i]=i
            f3[i]=f3[i-step]
       else:
            f1[i]=f1[i-step]
            f2[i]=f2[i-step]
            f3[i]=i
pass


def answer(cur, l,r,l1,r1):
    value1 = max(r-cur,r1-cur)
    value2 = max(cur-l, cur-l1)
    value3 = r-cur+(cur-l1)
    value4 = cur-l+(r1-cur)
    print(cur, value1, value2, value3, value4)

for t in range(int(input())):
    str1 = input()
    #f1 = [0]*200005
    #f2 = [0]*200005
    #f3 = [0]*200005
    l1 = [0]*(len(str1)+2)
    l2 = [0]*(len(str1)+2)
    l3 = [0]*(len(str1)+2)
    if str1.count('1')==0 or str1.count('2')==0 or str1.count('3')==0:
        print(0)
        continue
    #print(len(str1), str1)
    str1='0'+str1[0:len(str1)-1]
   # print(len(str1), str1)
    fi = 0
    li = 0
    minValue = 100000000
    #fun(str1,f1,f2,f3,1,len(str1),1)
    fun(str1,l1,l2,l3,len(str1)-1,0,-1)
    for i in range(1,len(str1)):
        if l1[i]==0 or l2[i]==0 or l3[i]==0:
            break
        if str1[i]=='1':
            value = max(l2[i]-i, l3[i]-i)
        elif str1[i]=='2':
            value = max(l1[i]-i, l3[i]-i)
        else:
            value = max(l1[i]-i, l2[i]-i)
        if minValue>value:
            minValue = value
            fi = i
            li = i+value+1
    
    print(li-fi)
    
    

    
    
    
    
    
    
    
    
    
    
    
        
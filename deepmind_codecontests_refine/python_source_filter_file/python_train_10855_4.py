#------------------------template--------------------------#
import os
import sys
from math import *
from collections import *
# from fractions import *
# from heapq import*
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
ALPHA='abcdefghijklmnopqrstuvwxyz/'
M=998244353
EPS=1e-6
def Ceil(a,b): return a//b+int(a%b>0)
def value():return tuple(map(int,input().split()))
def array():return [int(i) for i in input().split()]
def Int():return int(input())
def Str():return input()
def arrayS():return [i for i in input().split()]


#-------------------------code---------------------------#
# vsInput()


for _ in range(Int()):
    n=Int()
    a=array()

    ans=[]

    if(len(set(a))==1):
        print(0)
        continue

    for i in range(1,n):
        k=i+1
        
        ans.append((1,k,(k-a[i]%k)%k))
        a[0]-=k-a[i]%k
        a[i]+=k-a[i]%k 

        ans.append((k,1,a[i]//k))
        a[0]+=k*(a[i]//k)
        a[i]-=k*(a[i]//k)
        

        
        
    tot=sum(a)
    
    
    if(tot%n): print(-1)
    else:

        need=tot//n

        for i in range(1,n):
            here=need-a[i]

            a[i]+=here
            ans.append((1,i+1,here))
            a[0]-=here

        # print(*a)
        print(len(ans))
        for i in ans:
            print(*i)


        


    

        















    

    
    





    

    


        





    

        


    




        

        


    









    







    


















    
    
    



    
        

   










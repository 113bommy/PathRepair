#------------------------template--------------------------#
import os
import sys
# from math import *
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
ALPHA='abcdefghijklmnopqrstuvwxyz'
M=10**9+7
EPS=1e-6
def Ceil(a,b): return a//b+int(a%b>0)
def value():return tuple(map(int,input().split()))
def array():return [int(i) for i in input().split()]
def Int():return int(input())
def Str():return input()
def arrayS():return [i for i in input().split()]


#-------------------------code---------------------------#
# vsInput()


def get(s):

    if(s=="void" or s=='errtype'): return (s,0)


    c1,c2=0,0
    l=0
    while(s[l]=='&'):
        c1+=1
        l+=1
    r=len(s)-1
    while(s[r]=='*'):
        c2+=1
        r-=1

    if(r<l): return get('errtype')

    here=c2-c1+cat[s[l:r+1]][1]
    # print(s[l:r+1])

    ans=get(cat[s[l:r+1]][0])
    ans=(ans[0],ans[1]+here)
    return ans
    





n=Int()
cat=defaultdict(lambda : ('errtype',0))
cat['void']=('void',0)

for i in range(n):
    query=input()

    if('typeof' in query):
        _,var=query.split()
        ans=get(var)
        if(ans[1]<0 or ans[0]=='errtype'):
            ans=('errtype',0)

        print(ans[0],'*'*ans[1])
    else:
        _,ty,var=query.split()
        ans=get(ty)

        # print(ans)

        if(ans[1]<0 or ans[0]=='errtype'):
            ans=('errtype',0)
        cat[var]=ans

    







    


















    
    
    



    
        

   












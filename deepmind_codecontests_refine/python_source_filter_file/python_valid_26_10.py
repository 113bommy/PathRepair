#Fast I/O
import sys,os

#User Imports
from math import *
from bisect import *
from heapq import *
from collections import *

# To enable the file I/O i the below 2 lines are uncommented.
# read from in.txt if uncommented
if os.path.exists('in.txt'): sys.stdin=open('in.txt','r')
# will print on Console if file I/O is not activated
#if os.path.exists('out.txt'): sys.stdout=open('out.txt', 'w')

# inputs template
from io import BytesIO, IOBase

#Main Logic
def main():
    for  _ in range(int(input())):
        s=input()
        out=[]
        def all(i,cur=''):
            if i==10:
                out.append(cur)
                return
            if s[i]=="1":all(i+1,cur+"1")
            elif s[i]=="0":all(i+1,cur+"0")
            else:
                all(i+1,cur+"1")
                all(i+1,cur+"0")
        def check(st):
            a,b=0,0
            i=0
            while i<10:
                if st[i]=='1':
                    if i%2:b+=1
                    else:a+=1
                if a>b and a>b+5-i//2:return i+1
                if b>a and b>a+4-i//2:return i+1
                i+=1
            return 10
        all(0)
        ans=check(out[0])
        for j in out:
            ans=min(ans,check(j))
        print(ans)

# region fastio

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

#for array of integers
def MI():return (map(int,input().split()))
# endregion
#for fast output, always take string
def outP(var): sys.stdout.write(str(var)+'\n')  
# end of any user-defined functions

MOD=10**9+7
mod=998244353

# main functions for execution of the program.

if __name__ == '__main__':  
    #This doesn't works here but works wonders when submitted on CodeChef or CodeForces 
    main()
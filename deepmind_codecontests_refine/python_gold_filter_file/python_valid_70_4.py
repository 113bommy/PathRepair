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

def main():
    for _ in range(int(input())):
        t=input()
        possible=True
        c=Counter(t)
        order=[]
        k=len(c)
        n,l=len(t)-1,k
        f=defaultdict(lambda:0)
        prev=[]
        while n>=0 and l and possible:
            j=0
            nn=[]
            while n>=0 and f[t[n]]!=0 and j<len(prev):
                if prev[j]!=t[n]:
                    possible=False
                    break
                nn.append(t[n])
                j+=1
                n-=1
            if n<0:
                possible=False
                break
            if f[t[n]]==0:
                if c[t[n]]%l:
                    possible=False
                    break
                order.append(t[n])
                f[t[n]]=c[t[n]]//l
                u,h=c[t[n]]//l,t[n]
            while n>=0 and f[t[n]]!=0:
                if t[n]==h:
                    if u:
                        u-=1
                        nn.append(t[n])
                    elif j==len(prev):
                        break
                    else:
                        possible=False
                        break
                elif t[n]==prev[j]:
                    nn.append(prev[j])
                    j+=1
                else:
                    possible=False
                    break
                n-=1
                if u==0 and j==len(prev):break
            if u==0 and j==len(prev):pass
            else:
                possible=False
                break
            l-=1
            prev=nn
        if not possible or n>=0:
            print(-1)
        else:
            print("".join(prev[::-1]),"".join(order[::-1]))


        
            

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
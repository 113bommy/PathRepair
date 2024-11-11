#Fast I/O
import sys,os
import math
# To enable the file I/O i the below 2 lines are uncommented.
# read from in.txt if uncommented
if os.path.exists('in.txt'): sys.stdin=open('in.txt','r')
# will print on Console if file I/O is not activated
#if os.path.exists('out.txt'): sys.stdout=open('out.txt', 'w')

# inputs template
from io import BytesIO, IOBase


def main():
    import random,bisect
    n,q=MI()
    arr=list(MI())
    count=[list() for i in range(n+1)]
    for i in range(n):
        count[arr[i]].append(i)
    for _ in range(q):
        l,r=MI()
        l-=1
        r-=1
        m=(r-l+1)
        out=1
        s=set()
        for i in range(20):
            x=int(random.random() * (r - l + 1)) + l
            if arr[x] in s:
                continue
            s.add(arr[x])
            if len(count[arr[x]])<=(m+1)//2:
                continue
            ir=bisect.bisect_right(count[arr[x]],r)
            il=bisect.bisect_left(count[arr[x]],l)
            if ir-il>(m+1)//2:
                out=2*(ir-il)-m
                break
        outP(out)
            
# Sample Inputs/Output 
# 6 2
# 1 3 2 3 3 2
# 1 6
# 2 5

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

# main functions for execution of the program.

if __name__ == '__main__':  
    #This doesn't works here but works wonders when submitted on CodeChef or CodeForces 
    main()
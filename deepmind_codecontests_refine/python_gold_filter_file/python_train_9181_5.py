# by the authority of GOD   author: manhar singh sachdev #

import os,sys
from io import BytesIO,IOBase

def cons(n,x):
    xx = n.bit_length()
    dp = [[0]*n for _ in range(xx)]
    dp[0] = x
    for i in range(1,xx):
        for j in range(n-(1<<i)+1):
            dp[i][j] = max(dp[i-1][j],dp[i-1][j+(1<<(i-1))])
    return dp

def ask(l,r,dp):
    """ l and r inclusive 0 based"""
    xx1 = (r-l+1).bit_length()-1
    return max(dp[xx1][l],dp[xx1][r-(1<<xx1)+1])

def solve(n,a):
    day = [0]*(n+1)
    for _ in range(int(input())):
        p,s = map(int,input().split())
        day[s] = max(day[s],p)
    for i in range(n-1,-1,-1):
        day[i] = max(day[i],day[i+1])
    if max(a) > day[0]:
        return -1
    dp = cons(n,a)
    val,i = 0,0
    while i != n:
        hi,lo,ans = n-1,i,i
        while hi >= lo:
            mid = (hi+lo)//2
            maxi = ask(i,mid,dp)
            if day[mid-i+1] >= maxi:
                lo = mid+1
                ans = mid
            else:
                hi = mid-1
        i = ans+1
        val += 1
    return val

def main():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        print(solve(n,a))

# Fast IO Region
BUFSIZE = 8192
class FastIO(IOBase):
    newlines = 0
    def __init__(self,file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
    def read(self):
        while True:
            b = os.read(self._fd,max(os.fstat(self._fd).st_size,BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0,2),self.buffer.write(b),self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd,max(os.fstat(self._fd).st_size,BUFSIZE))
            self.newlines = b.count(b"\n")+(not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0,2),self.buffer.write(b),self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
    def flush(self):
        if self.writable:
            os.write(self._fd,self.buffer.getvalue())
            self.buffer.truncate(0),self.buffer.seek(0)
class IOWrapper(IOBase):
    def __init__(self,file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s:self.buffer.write(s.encode("ascii"))
        self.read = lambda:self.buffer.read().decode("ascii")
        self.readline = lambda:self.buffer.readline().decode("ascii")
sys.stdin,sys.stdout = IOWrapper(sys.stdin),IOWrapper(sys.stdout)
input = lambda:sys.stdin.readline().rstrip("\r\n")
if __name__ == "__main__":
    main()
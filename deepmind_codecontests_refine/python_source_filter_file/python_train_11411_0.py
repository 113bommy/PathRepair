# by the authority of GOD     author: manhar singh sachdev #

import os,sys
from io import BytesIO, IOBase

def add(x,y):
    for i in range(len(x)):
        x[i] += y[i]

def sub(x,y):
    for i in range(len(x)):
        x[i] -= y[i]

def main():
    n,q,c = map(int,input().split())
    arr = [[[0]*(c+1) for _ in range(101)] for _ in range(101)]
    for _ in range(n):
        x,y,s = map(int,input().split())
        arr[x][y][s] += 1
    dp = [[[0]*(c+1) for _ in range(101)] for _ in range(101)]
    for i in range(1,101):
        for j in range(1,101):
            add(dp[i][j],arr[i][j])
            add(dp[i][j],dp[i-1][j])
            add(dp[i][j],dp[i][j-1])
            sub(dp[i][j],dp[i-1][j-1])
    for _ in range(q):
        t,x1,y1,x2,y2 = map(int,input().split())
        x = dp[x2][y2][:]
        add(x,dp[x1-1][y1-1])
        sub(x,dp[x1-1][y2])
        sub(x,dp[x1][y1-1])
        ans = 0
        for ind,j in enumerate(x):
            ans += ((ind+t)%(c+1))*j
        print(ans)

#Fast IO Region
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

if __name__ == '__main__':
    main()
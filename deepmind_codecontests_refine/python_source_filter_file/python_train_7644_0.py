# by the authority of GOD     author: manhar singh sachdev #

import os,sys
from io import BytesIO, IOBase

def main():
    n,m = map(int,input().split())
    arr = [list(map(int,input().split())) for _ in range(n)]
    dp1 = [[0]*(m+2) for _ in range(n+2)]
    for i in range(1,n+1):
        for j in range(1,m+1):
            dp1[i][j] = max(dp1[i-1][j],dp1[i][j-1])+arr[i-1][j-1]
    dp2 = [[0]*(m+2) for _ in range(n+2)]
    for i in range(1,n+1):
        for j in range(m,0,-1):
            dp2[i][j] = max(dp2[i-1][j],dp2[i][j+1])+arr[i-1][j-1]
    dp3 = [[0]*(m+2) for _ in range(n+2)]
    for i in range(n,0,-1):
        for j in range(m,0,-1):
            dp3[i][j] = max(dp3[i+1][j],dp3[i][j+1])+arr[i-1][j-1]
    dp4 = [[0]*(m+2) for _ in range(n+2)]
    for i in range(n,0,-1):
        for j in range(1,m+1):
            dp4[i][j] = max(dp4[i+1][j],dp4[i][j-1])+arr[i-1][j-1]
    maxi = 0
    for i in range(1,n+1):
        for j in range(1,m+1):
            maxi = max(maxi,
                       dp1[i][j-1]+dp4[i+1][j]+dp2[i-1][j]+dp3[i][j+1],
                       dp1[i-1][j]+dp4[i][j-1]+dp2[i][j+1]+dp3[i+1][j]
                       )
    print(maxi)

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
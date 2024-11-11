import os
import sys
from io import BytesIO, IOBase
 
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
print = sys.stdout.write

inf = float('inf')
def solve():
    n,m = map(int,input().split())
    M = [list(map(int,input().split())) for _ in range(n)]

    pmn = [[0]*m for _ in range(n)]
    pmx = [[0]*m for _ in range(n)]
    smn = [[0]*m for _ in range(n)]
    smx = [[0]*m for _ in range(n)]
    
    for i in range(n):
        for j in range(m):
            if j>=1:
                pmn[i][j] = min(pmn[i][j-1], M[i][j])
                pmx[i][j] = max(pmx[i][j-1], M[i][j])
            else:
                pmn[i][j] = M[i][j]
                pmx[i][j] = M[i][j]

    for i in range(n):
        for j in range(m-1,-1,-1):
            if j+1<m:
                smn[i][j] = min(smn[i][j+1], M[i][j])
                smx[i][j] = max(smx[i][j+1], M[i][j])
            else:
                smn[i][j] = M[i][j]
                smx[i][j] = M[i][j]

    I = list(range(0,n))
    for j in range(0,m-2):
        I.sort(key = lambda i: -pmn[i][j])
        cmx = -inf
        cmn = inf

        D = [smx[i0][j+1] for i0 in I]
        for i in range(1,n):
            D[i] = max(D[i], D[i-1])

        for _ in range(n-1,0,-1):
            i0 = I[_]
            i1 = I[_-1]

            cmx = max(cmx, pmx[i0][j])
            cmn = min(cmn, smn[i0][j+1])

            if pmn[i1][j] > cmx and D[_-1]<cmn:
                ans = ["B"]*n
                idx = 0
                while I[idx] != i1:
                    ans[I[idx]] = "R"
                    idx += 1

                ans[i1] = "R"
                print("YES\n")
                print("".join(ans) + " " + str(j+1) + "\n" )
                return

    print("NO\n")

for nt in range(int(input())):
    solve()

import os
import sys
from io import BytesIO, IOBase
import math
 
#--------------------fastio--------------------

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


if(os.path.exists('input.txt')):
    sys.stdin = open('input.txt','r') ; sys.stdout = open('output.txt','w')
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
    input = lambda: sys.stdin.readline().rstrip("\r\n")

def f(i):
    if a[i] > a[i+1]:
        a[i],a[i+1] = a[i+1], a[i]

for t in range(int(input())):
    a,b = map(int, input().split())
    if a==b:
        ans = [i for i in range(0,2*a + 1,2)]
        print(len(ans))
        print(*ans)
    elif abs(a-b) == 1:
        print(a+b+1)
        print(*[i for i in range(a+b+1)])
    elif (a+b)//2 == 0:
        ans = [i for i in range(0 + abs(a-b)//2, 1+a+b-abs(a-b)//2, 2)]
        print(len(ans))
        print(*ans)
    else:
        ans = [i for i in range(0 + abs(a-b)//2, 1+a+b-abs(a-b)//2)]
        print(len(ans))
        print(*ans)

    

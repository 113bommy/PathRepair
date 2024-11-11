#!/usr/bin/env python
import os
import sys
from io import BytesIO, IOBase


def main():
    for _ in range(int(input())):
        n,m = map(int,input().split())
        grid = []
        for _ in range(n):
            grid.append(input())
        ans = []
        for i in range(0,n,2):
            for j in range(0,m,2):
                if grid[i][j] == '1':
                    if i == n-1:
                        iP2 = i
                    else:
                        iP2 = i + 2
                    if j == n-1:
                        jP2 = j
                    else:
                        jP2 = j + 2
                    ans.append([i + 1, j + 1, iP2, jP2, iP2, j + 1])
                    ans.append([i + 1, j + 1, i + 1, jP2, iP2 , jP2])
                    ans.append([i + 1, j + 1, iP2 , j + 1, i + 1, jP2])
        print(len(ans))
        for lineAns in ans:
            print(" ".join(map(str,lineAns)))


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

# endregion

if __name__ == "__main__":
    main()
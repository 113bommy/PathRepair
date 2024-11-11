#!/usr/bin/env python
import os
import sys
from io import BytesIO, IOBase


def main():
    pass


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


def solve(x, y):
    one = 0
    for s in range(x, x+2):
        for r in range(y, y+2):
            if arr[s][r] == '1':
                one += 1
    if one == 3:
        for s in range(x, x + 2):
            for r in range(y, y + 2):
                if arr[s][r] == '1':
                    ans.append(s+1)
                    ans.append(r+1)
                    arr[s][r] = '0'
    if one == 2:
        c = 0
        for s in range(x, x + 2):
            for r in range(y, y + 2):
                if arr[s][r] == '0':
                    ans.append(s+1)
                    ans.append(r+1)
                    arr[s][r] = '1'
                elif c == 0:
                    ans.append(s+1)
                    ans.append(r+1)
                    c += 1
                    arr[s][r] = '0'
        for s in range(x, x + 2):
            for r in range(y, y + 2):
                if arr[s][r] == '1':
                    ans.append(s+1)
                    ans.append(r+1)
                    arr[s][r] = '0'
    if one == 1:
        c = 0
        for s in range(x, x + 2):
            for r in range(y, y + 2):
                if arr[s][r] == '0' and c < 2:
                    ans.append(s+1)
                    ans.append(r+1)
                    c += 1
                    arr[s][r] = '1'
                elif arr[s][r] == '1':
                    ans.append(s+1)
                    ans.append(r+1)
                    arr[s][r] = '0'
        c = 0
        for s in range(x, x + 2):
            for r in range(y, y + 2):
                if arr[s][r] == '0':
                    ans.append(s+1)
                    ans.append(r+1)
                    arr[s][r] = '1'
                elif c == 0:
                    ans.append(s+1)
                    ans.append(r+1)
                    c += 1
                    arr[s][r] = '0'
        for s in range(x, x + 2):
            for r in range(y, y + 2):
                if arr[s][r] == '1':
                    ans.append(s+1)
                    ans.append(r+1)
                    arr[s][r] = '0'

    if one == 4:
        c = 0
        for s in range(x, x+2):
            for r in range(y, y+2):
                if c < 3:
                    ans.append(s+1)
                    ans.append(r+1)
                    c += 1
                    arr[s][r] = '0'
        c = 0
        for s in range(x, x + 2):
            for r in range(y, y + 2):
                if arr[s][r] == '0' and c < 2:
                    ans.append(s+1)
                    ans.append(r+1)
                    c += 1
                    arr[s][r] = '1'
                elif arr[s][r] == '1':
                    ans.append(s+1)
                    ans.append(r+1)
                    arr[s][r] = '0'
        c = 0
        for s in range(x, x + 2):
            for r in range(y, y + 2):
                if arr[s][r] == '0':
                    ans.append(s+1)
                    ans.append(r+1)
                    arr[s][r] = '1'
                elif c == 0 and arr[s][r] == '1':
                    ans.append(s+1)
                    ans.append(r+1)
                    c += 1
                    arr[s][r] = '0'
        for s in range(x, x + 2):
            for r in range(y, y + 2):
                if arr[s][r] == '1':
                    ans.append(s+1)
                    ans.append(r+1)
                    arr[s][r] = '0'


for _ in range(int(input())):
    n, m = map(int, input().split())
    arr = []
    ans = []
    for i in range(n):
        arr.append(list(input()))
    if n % 2 == 0 and m % 2 == 0:
        for i in range(0, n-1, 2):
            for j in range(0, m-1, 2):
                solve(i, j)
    elif n % 2 == 1 and m % 2 == 1:
        i = 0
        while i < n-1:
            j = 0
            while j < m-1:
                solve(i, j)
                if j != m-3:
                    j += 2
                else:
                    j += 1
            if i != n-3:
                i += 2
            else:
                i += 1
    elif n % 2 == 1:
        i = 0
        while i < n-1:
            j = 0
            while j < m-1:
                solve(i, j)
                j += 2
            if i != n-3:
                i += 2
            else:
                i += 1
    else:
        i = 0
        while i < n - 1:
            j = 0
            while j < m - 1:
                solve(i, j)
                if j != m - 3:
                    j += 2
                else:
                    j += 1
            i += 2

    c = 0
    print(len(ans) // 6)
    for i in range(len(ans)):
        print(ans[i], end=' ')
        c += 1
        if c == 6:
            c = 0
            print('')



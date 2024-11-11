#!/usr/bin/env python
import os
import sys
from io import BytesIO, IOBase


def main():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        cnt = 0
        aCnt = [0] * n
        for i in range(n):
            aCnt[a[i] - 1] += 1
        flag = True
        for elem in aCnt:
            if elem > n - (n // 2):
                flag = False
        if not flag:
            print(-1)
            continue
        endCountDouble = [0] * (n + 1)
        endCountSingle = [0] * (n + 1)
        last = a[0]
        lastInd = 0
        for i in range(n-1):
            if a[i] == a[i + 1]:
                cnt += 1
                if last == a[i]:
                    endCountDouble[last] += 1
                else:
                    endCountSingle[last] += 1
                    endCountSingle[a[i]] += 1
                    last = a[i]
                lastInd = i
        if last == a[n-1]:
            endCountDouble[last] += 1
        else:
            endCountSingle[last] += 1
            endCountSingle[a[n-1]] += 1
            last = a[n-1]
        segCount = cnt + 1
        adjCount = 0
        whattoAdj = 0
        for i in range(n + 1):
            if endCountDouble[i] > (segCount - endCountSingle[i]) - (segCount - endCountSingle[i]) // 2:
                adjCount = endCountDouble[i] - ((segCount - endCountSingle[i]) - (segCount - endCountSingle[i]) // 2)
                whattoAdj = i
        if adjCount != 0:
            badPair = endCountDouble[whattoAdj]
            goodPair = segCount - endCountSingle[whattoAdj] - endCountDouble[whattoAdj]
            adjAble = 0
            for i in range(n - 1):
                if a[i] != i and a[i + 1] != i:
                    adjAble += 1
            if adjAble >= badPair - goodPair:
                print(cnt + badPair - goodPair)
            else:
                print(-1)
        else:
            print(cnt)



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
# import itertools
# import bisect
import math
from collections import defaultdict
import os
import sys
from io import BytesIO, IOBase

# sys.setrecursionlimit(10 ** 5)
ii = lambda: int(input())
lmii = lambda: list(map(int, input().split()))
slmii = lambda: sorted(map(int, input().split()))
li = lambda: list(input())
mii = lambda: map(int, input().split())
msi = lambda: map(str, input().split())


def gcd(a, b):
    if b == 0: return a
    return gcd(b, a % b)


def lcm(a, b): return (a * b) // gcd(a, b)


def main():
    # for _ in " " * int(input()):
    n, x1, y1, x2, y2 = mii()
    lst = []
    for i in range(n):
        x, y = mii()
        lst.append([x, y])
    s1 = 0
    s2 = 0
    for i in range(n):
        if i == 0:
            s1 = math.pow((lst[i][0] - x1), 2) + math.pow((lst[i][1] - y1), 2)
            s2 = math.pow((lst[i][0] - x2), 2) + math.pow((lst[i][1] - y2), 2)
        else:
            s1 = max(s1, math.pow((lst[i][0] - x1), 2) + math.pow((lst[i][1] - y1), 2))
            s2 = max(s2, math.pow((lst[i][0] - x2), 2) + math.pow((lst[i][1] - y2), 2))
    ans = min(s1, s2)
    for i in range(n):
        dist = math.pow((lst[i][0] - x1), 2) + math.pow((lst[i][1] - y1), 2)
        fst = 0
        for j in range(n):
            if math.pow((lst[j][0] - x1), 2) + math.pow((lst[j][1] - y1), 2) > dist:
                fst = max(fst, math.pow((lst[j][0] - x2), 2) + math.pow((lst[j][1] - y2), 2))
        ans = min(ans, dist + fst)
    print(int(ans))


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

if __name__ == "__main__":
    main()

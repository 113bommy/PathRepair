import os
import sys
from io import BytesIO, IOBase
import math
from decimal import *

getcontext().prec = 25

MOD = pow(10, 9) + 7
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


def binary_search(data, val, le):
    test = le
    if val >= data[-1]:
        return [test - 1, test - 1]
    elif val <= data[0]:
        return [0, 0]
    high_index = test - 1
    low_index = 0
    while high_index > low_index:
        index = (high_index + low_index) // 2
        sub = data[index]
        if data[low_index] == val:
            return [low_index, low_index]
        elif sub == val:
            return [index, index]
        elif data[high_index] == val:
            return [high_index, high_index]
        elif sub > val:
            if high_index == index:
                return sorted([high_index, low_index])
            high_index = index
        else:
            if low_index == index:
                return sorted([high_index, low_index])
            low_index = index
    return sorted([high_index, low_index])


# n, k = map(int, input().split(" "))
# l = list(map(int, input().split(" ")))

n = int(input())
l = [int(input()) for i in range(n)]
l.sort()
a = l[-1] // 2
x = binary_search(l, a, n)[0]
while l[x] <= a:
    x += 1
if x > n // 2:
    x = n//2 + n%2
i = 0
c = 0
while l[i] <= a and x < n:
    if l[i] <= l[x] // 2:
        c += 1
        i += 1
        x += 1
    else:
        x += 1
# print(*l)
# print(a)

print(n-c)

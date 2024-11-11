from collections import *
import os, sys
from io import BytesIO, IOBase
from itertools import combinations


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, 8192))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, 8192))
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
inp = lambda dtype: dtype(input().strip())
inp_d = lambda dtype: [dtype(x) for x in input().split()]
inp_2d = lambda dtype, n: [inp(dtype) for _ in range(n)]
inp_2ds = lambda dtype, n: [inp_d(dtype) for _ in range(n)]
inp_enu = lambda dtype: [(i, x) for i, x in enumerate(inp_d(dtype))]
inp_enus = lambda dtype, n: [[i, inp_d(dtype)] for i in range(n)]
ceil1 = lambda a, b: (a + b - 1) // b

for _ in range(inp(int)):
    n, a = inp(int), inp_d(int)
    good = 2 * n - 1

    for i in range(2, n):
        good += not (a[i - 2] >= a[i - 1] >= a[i] or a[i - 2] <= a[i - 1] <= a[i])

    for i in range(4, n + 1):
        bad = False
        for com in combinations(a[i - 4:i], 3):
            bad |= com[0] >= com[1] >= com[2] or com[0] <= com[1] <= com[2]
        good += 1 - bad

    print(good)

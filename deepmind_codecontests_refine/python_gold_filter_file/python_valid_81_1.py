import os, sys
from io import BytesIO, IOBase


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


class dict(dict):
    def __missing__(self, key):
        return 0


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
inp = lambda dtype: [dtype(x) for x in input().split()]
inp_2d = lambda dtype, n: [dtype(input()) for _ in range(n)]
inp_2ds = lambda dtype, n: [inp(dtype) for _ in range(n)]
inp_enu = lambda dtype: [(i, x) for i, x in enumerate(inp(dtype))]
inp_enus = lambda dtype, n: [[i] + [inp(dtype)] for i in range(n)]
ceil1 = lambda a, b: (a + b - 1) // b

for _ in range(int(input())):
    n, q = inp(int)
    s = input()
    cum0, cum1 = [0], [0, 0]

    for i in range(n):
        sign = -1 if (i & 1) else 1
        if s[i] == '+':
            cum0.append(cum0[-1] + sign)
        else:
            cum0.append(cum0[-1] + (sign * -1))

    for i in range(1, n):
        sign = 1 if (i & 1) else -1
        if s[i] == '+':
            cum1.append(cum1[-1] + sign)
        else:
            cum1.append(cum1[-1] + (sign * -1))

    for _ in range(q):
        l, r = inp(int)
        d = 0
        if l & 1:
            d = abs(cum0[r] - cum0[l - 1])
        else:
            d = abs(cum1[r] - cum1[l - 1])

        if d & 1:
            print(1)
        elif d > 1:
            print(2)
        else:
            print(d)

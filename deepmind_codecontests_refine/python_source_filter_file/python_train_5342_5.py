from __future__ import division, print_function
import math
import os
import sys
from io import BytesIO, IOBase

if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip
def o1(l, n):
    for i in range(0, n+n, 2):
        l[i], l[i + 1] = l[i + 1], l[i]
    # print("o1",l)
    return l


def o2(l, n):
    for i in range(0, n):
        l[i], l[n + i] = l[n + i], l[i]
    # print("o2",l)
    return l

def main():
    n = int(input())
    l = list(map(int, input().split()))
    a1 = 0
    a2 = 0
    k1 = k2 = True
    l1 = list(l)
    l1.sort()
    l2 = list(l)
    while (l != l1):
        # print(l)
        if (a1 % 2==0):
            l = o1(l, n)
        else:
            l = o2(l, n)
        a1 += 1
        if (a1 > 1000):
            k1 = False
            break
    # print(l)
    while (l2 != l1):
        # print(l2)
        if (a2 % 2==0):
            l2 = o2(l2, n)
        else:
            l2 = o1(l2, n)
        a2 += 1
        if (a2 > 1000):
            k2 = False
            break
    # print(l,l2)
    if (k1 and k2):
        print(min(a1, a2))
    else:
        print(-1)
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


def print(*args, **kwargs):
    """Prints the values to a stream, or to sys.stdout by default."""
    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", False):
        file.flush()


if sys.version_info[0] < 3:
    sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)

input = lambda: sys.stdin.readline().rstrip("\r\n")

# endregion

if __name__ == "__main__":
    main()
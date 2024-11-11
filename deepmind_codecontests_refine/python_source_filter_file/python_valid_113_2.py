import decimal
import math
import os
import sys
from collections import Counter
from io import BytesIO, IOBase
import bisect

BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = 'x' in file.mode or 'r' not in file.mode
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
            self.newlines = b.count(b'\n') + (not b)
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
        self.write = lambda s: self.buffer.write(s.encode('ascii'))
        self.read = lambda: self.buffer.read().decode('ascii')
        self.readline = lambda: self.buffer.readline().decode('ascii')


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip('\r\n')


def ints_get(): return map(int, input().strip().split())


def list_get(): return list(map(int, sys.stdin.readline().strip().split()))


def chars_get(): return list(map(str, sys.stdin.readline().strip().split()))


def output(to_be_printed, end="\n"): sys.stdout.write(str(to_be_printed) + end)


# ******************************************************#
# **************** code starts here ********************#
# ******************************************************#


def main():
    n = int(input())
    a = list_get()
    a.sort()
    m = int(input())
    s = sum(a)
    v = []
    for _ in range(m):
        x, y = ints_get()
        val = bisect.bisect(a, x)
        ans = 10**18
        if val == 0:
            p = s - a[0]
            ans = min(ans, max(0, y - p))
        elif val == n:
            p = s - a[n - 1]
            ans = min(ans, max(0, y - p) + max(0, x - a[n - 1]))
        else:
            p = s - a[val]
            ans = min(ans, max(0, y - p))
            p = s - a[val - 1]
            ans = min(ans, max(0, y - p) + max(0, x - a[val - 1]))
        print(ans)
    return

if __name__ == "__main__":
    main()



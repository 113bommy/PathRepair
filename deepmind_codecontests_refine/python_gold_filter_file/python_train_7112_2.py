import os
import sys
from io import BytesIO, IOBase

_print = print
BUFSIZE = 8192


def dbg(*args, **kwargs):
    _print('\33[95m', end='')
    _print(*args, **kwargs)
    _print('\33[0m', end='')


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


def inp():
    return sys.stdin.readline().rstrip()


def mpint():
    return map(int, inp().split(' '))


def itg():
    return int(inp())


# ############################## import
# ############################## main
"""
maximize c+d, s.t.
ac + bd <= x
bc + ad <= y
"""


def solve():
    x, y, a, b = mpint()
    max_c = min(x // a, y // b)
    max_d = min(x // b, y // a)
    r1 = x - a * max_c
    b1 = y - b * max_c
    r2 = x - a * max_d
    b2 = y - b * max_d
    cramer = 0
    if a * a - b * b != 0:
        cc = (x * a - b * y) // (a * a - b * b)
        dd = (a * y - x * b) // (a * a - b * b)
        for i, j in ((0, 0), (0, 1), (1, 0), (1, 1)):
            c0 = max(0, cc + i)
            d0 = max(0, dd + j)
            if a * c0 + b * d0 <= x and b * c0 + a * d0 <= y:
                cramer = max(cramer, c0 + d0)
            c0 = max(0, cc - i)
            d0 = max(0, cc - j)
            if a * c0 + b * d0 <= x and b * c0 + a * d0 <= y:
                cramer = max(cramer, c0 + d0)
    return max(max_c + (r1 >= b and b1 >= a), max_d + (r2 >= a and b2 >= b), cramer)


def main():
    # print(solve())
    for _ in range(itg()):
        print(solve())
        # solve()
        # print("YES" if solve() else "NO")
        # print("yes" if solve() else "no")


DEBUG = 0
URL = 'https://codeforces.com/contest/1538/problem/G'

if __name__ == '__main__':
    # 0: normal, 1: runner, 2: debug, 3: interactive
    if DEBUG == 1:
        import requests
        from ACgenerator.Y_Test_Case_Runner import TestCaseRunner

        runner = TestCaseRunner(main, URL)
        inp = runner.input_stream
        print = runner.output_stream
        runner.checking()
    else:
        if DEBUG != 2:
            dbg = lambda *args, **kwargs: ...
            sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
        if DEBUG == 3:
            def print(*args, **kwargs):
                _print(*args, **kwargs)
                sys.stdout.flush()
        main()
# Please check!

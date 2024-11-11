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
def discrete_binary_search(func, lo, hi):
    while lo < hi:
        mi = lo + hi >> 1
        if func(mi):
            hi = mi
        else:
            lo = mi + 1
    return lo


def to_mask(num, size=None) -> list:
    """to_mask(11, 5) -> [0, 1, 0, 1, 1]"""
    if size is None:
        size = num.bit_length()
    result = [0] * size
    for index in reversed(range(size)):
        if num & 1:
            result[index] = 1
        num >>= 1
    return result


def binary_poly(iterable) -> int:
    """[1, 2, 3] -> 1*4 + 2*2 + 3*1 = 11"""
    result = 0
    for item in iterable:
        result <<= 1
        result += item
    return result


# ############################## main
def solve():
    n, m = mpint()
    if n > m:
        return 0
    # n <= m
    # ans = min x s.t. x^n > m
    # ans1 = discrete_binary_search(lambda ans: ans ^ n > m, 0, m + 1)
    size = m.bit_length() + 1
    ans = []
    for a, b in zip(to_mask(n, size=size), to_mask(m + 1, size=size)):
        if a == 0:
            ans.append(b)
        elif b == 0:
            break
        else:
            ans.append(0)

    return binary_poly(ans + [0] * (size - len(ans)))


def main():
    # print(solve())
    for _ in range(itg()):
        print(solve())
        # solve()
        # print("YES" if solve() else "NO")
        # print("yes" if solve() else "no")


DEBUG = 0
URL = 'https://codeforces.com/contest/1554/problem/C'

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

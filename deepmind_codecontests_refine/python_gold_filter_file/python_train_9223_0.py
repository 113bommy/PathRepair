import os
import sys
from io import BytesIO, IOBase

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


def inp():
    return sys.stdin.readline().rstrip()


def mpint():
    return map(int, inp().split(' '))


def itg():
    return int(inp())


# ############################## import
# ############################## main
def solve():
    """
    The answer is True iff
    their exist x, y is Z+ s.t.
    xy^2 = a && yx^2 = b
    -> x = (b^2 / a)^(1/3)

    """
    a, b = mpint()
    x = round((b * b // a) ** (1 / 3))
    if not x:
        return False
    y = round((a // x) ** 0.5)
    return a == x * y * y and b == y * x * x


def main():
    # solve()
    # print(solve())
    for _ in range(itg()):
        # print(solve())
        # solve()
        print("Yes" if solve() else "No")
        # print("YES" if solve() else "NO")


DEBUG = 0
URL = 'https://codeforces.com/problemset/problem/833/A'

if __name__ == '__main__':
    if DEBUG == 1:
        import requests  # ImportError: cannot import name 'md5' from 'sys' (unknown location)
        from ACgenerator.Y_Test_Case_Runner import TestCaseRunner

        runner = TestCaseRunner(main, URL, 1)
        inp = runner.input_stream
        print = runner.output_stream
        runner.checking()
    elif DEBUG == 2:
        main()
    else:
        sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
        main()
# Please check!

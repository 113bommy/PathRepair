#    !/usr/bin/env python3
#    encoding: UTF-8
#    Modified: <29/Sep/2019 07:11:16 PM>


#    ✪ H4WK3yE乡
#    Mohd. Farhan Tahir
#    Indian Institute Of Information Technology (IIIT), Gwalior


import sys
import os
from io import IOBase, BytesIO


def main():
    n, m = get_ints()
    r = get_array()
    c = get_array()
    mod = 10 ** 9 + 7
    arr = [[0 for j in range(m)] for i in range(n)]
    for i in range(n):
        for j in range(r[i]):
            arr[i][j] = 1
        if r[i] != m:
            arr[i][r[i]] = 2
    for i in range(m):
        for j in range(c[i]):
            if arr[j][i] == 2:
                print(0)
                return
            arr[j][i] = 1
        if c[i] != n:
            if arr[i][j] == 1:
                print(0)
                return
            arr[c[i]][i] = 2
    # print(arr)
    cnt = 0
    for i in range(1, n):
        for j in range(1, m):
            if arr[i][j] == 0:
                # print(i, j)
                cnt += 1

    cnt %= mod
    print(pow(2, cnt, mod) % mod)


BUFSIZE = 8192


class FastIO(BytesIO):
    newlines = 0

    def __init__(self, file):
        self._file = file
        self._fd = file.fileno()
        self.writable = "x" in file.mode or "w" in file.mode
        self.write = super(FastIO, self).write if self.writable else None

    def _fill(self):
        s = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
        self.seek((self.tell(), self.seek(0, 2), super(FastIO, self).write(s))[0])
        return s

    def read(self):
        while self._fill():
            pass
        return super(FastIO, self).read()

    def readline(self):
        while self.newlines == 0:
            s = self._fill()
            self.newlines = s.count(b"\n") + (not s)
        self.newlines -= 1
        return super(FastIO, self).readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.getvalue())
            self.truncate(0), self.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        py2 = round(0.5)
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        if py2 == 1:
            self.write = self.buffer.write
            self.read = self.buffer.read
            self.readline = self.buffer.readline
        else:
            self.write = lambda s: self.buffer.write(s.encode("ascii"))
            self.read = lambda: self.buffer.read().decode("ascii")
            self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)


def get_array():
    return list(map(int, sys.stdin.readline().split()))


def get_ints():
    return map(int, sys.stdin.readline().split())


def input():
    return sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
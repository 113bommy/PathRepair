#!/usr/bin/env python
import os
import sys
from io import BytesIO, IOBase
from bisect import bisect_left
from math import gcd, log, ceil
from collections import Counter
from pprint import pprint
import heapq

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
# endregion


def main():
    n, k = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    n = len(arr)
    if n == 1:
        return arr[0] + 1
    vals = [-1 for _ in range(n)]
    start = 0
    # if arr[0] == arr[1] - 1:
    #     vals[0] = min(8, k)
    #     if k <= 8:
    #         k = 0
    #     else:
    #         k -= 8

    #     start = 1
    # else:
    #     start = 0
    for i in range(start, n - 1):
        if k <= 0:
            break
        next_val = 10 ** arr[i + 1]
        if i == 0:
            max_remove = (next_val // (10 ** arr[i])) - 2
        else:
            max_remove = (next_val // (10 ** arr[i])) - 1

        vals[i] = min(max_remove, k)
        k -= max_remove

    # print(vals, k)

    ans = 0
    for i in range(n - 1):
        ans += (10 ** arr[i]) * max(vals[i], 0)
    if k > 0:
        ans += (10 ** arr[-1]) * k

    return ans + 1

    """
        10 ^ ai 
        f(s) -> min coins to make s 
        1 is always there 

        s -> new value
        f(s) > k 
        
        13 
            9, 5
        255 
            9, 99, 148 
    
    """


if __name__ == "__main__":
    for _ in range(int(input())):
        ans = main()
        print(ans)

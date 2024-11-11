#!/usr/bin/env python
import os
import sys
from io import BytesIO, IOBase
import math
from collections import Counter


def func(n, array):
    if 1 not in array:
        return " ".join(str(i) for i in range(1, n + 2))
    elif 0 not in array:
        return f"{n+1} " + " ".join(str(i) for i in range(1, n + 1))
    elif array[-1] == 0:
        return " ".join(str(i) for i in range(1, n + 2))
    else:
        for i, val in enumerate(array[:-1]):
            if array[i] == 0 and array[i + 1] == 1:
                # print(i)
                result = list(range(1, i + 2)) + [n + 1] + list(range(i + 2, n + 1))
                return " ".join(str(i) for i in result)


def main():
    num_test = int(parse_input())
    result = []
    for _ in range(num_test):
        n = int(parse_input())
        array = [int(i) for i in parse_input().split()]
        result.append(func(n, array))
    print("\n".join(map(str, result)))


# region fastio

# BUFSIZE = 8192


# class FastIO(IOBase):
#     newlines = 0

#     def __init__(self, file):
#         self._fd = file.fileno()
#         self.buffer = BytesIO()
#         self.writable = "x" in file.mode or "r" not in file.mode
#         self.write = self.buffer.write if self.writable else None

#     def read(self):
#         while True:
#             b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
#             if not b:
#                 break
#             ptr = self.buffer.tell()
#             self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
#         self.newlines = 0
#         return self.buffer.read()

#     def readline(self):
#         while self.newlines == 0:
#             b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
#             self.newlines = b.count(b"\n") + (not b)
#             ptr = self.buffer.tell()
#             self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
#         self.newlines -= 1
#         return self.buffer.readline()

#     def flush(self):
#         if self.writable:
#             os.write(self._fd, self.buffer.getvalue())
#             self.buffer.truncate(0), self.buffer.seek(0)


# class IOWrapper(IOBase):
#     def __init__(self, file):
#         self.buffer = FastIO(file)
#         self.flush = self.buffer.flush
#         self.writable = self.buffer.writable
#         self.write = lambda s: self.buffer.write(s.encode("ascii"))
#         self.read = lambda: self.buffer.read().decode("ascii")
#         self.readline = lambda: self.buffer.readline().decode("ascii")


# sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
parse_input = lambda: sys.stdin.readline().rstrip("\r\n")

# endregion

if __name__ == "__main__":
    main()

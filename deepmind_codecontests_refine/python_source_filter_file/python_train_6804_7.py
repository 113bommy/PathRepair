from __future__ import division, print_function

import os
import sys
from io import BytesIO, IOBase

def main():
    n, k = [ int(x) for x in input().split() ]
    array = [ int(x) for x in input().split() ]
    array.sort()

    accumulated = [0] * n
    accumulated[0] = array[0]
    for i in range(1, n):
        accumulated[i] = accumulated[i-1] + array[i]

    maxNumOfOccurrences = 1
    minNumThatMeetsCondition = array[-1]

    for i in range(1, n):
        left, right = 0, i - 1

        while left <= right:
            mid = (left + right) // 2

            expectedSum = array[i]*(i - mid + 1)
            realSum = accumulated[i] - (
                accumulated[left - 1] if left > 0 else 0
            )
            numOfOperations = expectedSum - realSum

            if numOfOperations <= k:
                right = mid - 1
            else:
                left = mid + 1

        if numOfOperations > k:
            mid += 1

        if i - mid + 1 > maxNumOfOccurrences:
            maxNumOfOccurrences = i - mid + 1
            minNumThatMeetsCondition = array[i]

    print(maxNumOfOccurrences, minNumThatMeetsCondition)

    # binary search
    # sort the array of numbers
    # array de soma acumulada

    # for each i -> get the max number of previous elements that
    # can be transformed into array[i], without exceeding k
        # if ok -> high = mid - 1
        # else -> low = mid + 1

        # remember to check if the sum at mid is still lower or equal than
        # k after finding the answer


BUFFSIZE = 8192

class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFFSIZE))
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

input = lambda: sys.stdin.readline().rstrip("\r\n")

def print(*args, **kwargs):
    sep = kwargs.pop("sep", " ")
    file = kwargs.pop("file", sys.stdout)

    atStart = True
    for x in args:
        if not atStart:
            file.write(sep)
        file.write(str(x))
        atStart = False
    file.write(kwargs.pop("end", "\n"))

    if kwargs.pop("flush", False):
        file.flush()

sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)

main()

"""
NTC here
"""


#!/usr/bin/env python
import os
import sys
from io import BytesIO, IOBase

def iin(): return int(input())


def lin(): return list(map(int, input().split()))

dc = {0:int('1110111', 2), 1:int("0010010", 2), 2:int("1011101", 2), 3:int("1011011", 2), 4:int("0111010", 2), 5:int("1101011", 2), 6:int("1101111", 2), 7:int("1010010", 2), 8:int("1111111", 2), 9:int("1111011", 2)}

def main():
    def ones_count(a):
        # a : int
        ba = bin(a)
        return ba.count('1')
    def get_all(x):
        ans = []
        ox = ones_count(x)
        for i in range(10):
            if x|dc[i]==dc[i]:
                ans.append([i, ones_count(dc[i])-ox])
                # ans[i] = ones_count(dc[i])-ox
        return ans
    T = 1
    for _ in range(T):
        n, k = lin()
        # print(dc)
        a = [get_all(int(input(), 2)) for i in range(n)]
        # a1 = [sorted(list(a[i].keys())) for i in range(n)]
        a = a[::-1]
        # a1 = a1[::-1]
        # print(a)
        ans = [[-1 for i in range(k+1)] for j in range(n)]
        for i, j in a[0]:
            # j = a[0][i]
            if j<=k:ans[0][j] = max(ans[0][j], i)
        # print(ans[0])
        for i in range(1, n):
            # print('all - ', a[i])
            for j in range(k+1):
                j1 = ans[i-1][j]
                if j1>=0:
                    # print(ans[i], j)
                    for k1, l in a[i]:
                        # l = a[i][k1]
                        if j+l<=k:
                            ans[i][j+l] = max(ans[i][j+l], j1)
                            # if ans[i][j+l]>-1:
                            #     pv = ans[i][j+l]
                            #     if ans[i-1][j+l-a[i][pv]]<j1:
                            #         ans[i][j+l] = k1
                            #     elif ans[i-1][j+l-a[i][pv]]==j1 and ans[i][j+l]<k1:
                            #         ans[i][j+l] = k1
                            # else:
                            #     ans[i][j+l]= k1 
        # print(*ans, sep='\n')
        if ans[-1][k]>-1:
            sol = []
            j = k
            for i in range(n-1, -1, -1):
                if j<0:
                    print(-1)
                    break
                sol.append(ans[i][j])
                step = 0
                for l, m in a[i]:
                    if l==ans[i][j]:
                        step = m
                        break
                j -= step
            else:
                # sol = sol[::-1]
                print(*sol, sep='')
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


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

# endregion

if __name__ == "__main__":
    main()
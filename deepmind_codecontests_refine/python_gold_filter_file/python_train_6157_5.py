import os
import sys
from io import BytesIO, IOBase
from collections import defaultdict, deque, Counter, OrderedDict
import threading

def main():
    def dir(v):
        if v=='U': return [0,1]
        if v=='D': return [0,-1]
        if v=='L': return [-1,0]
        if v=='R': return [1,0]
    x1,y1 = map(int,input().split())
    x2,y2 = map(int,input().split())
    n = int(input())
    s = input()
    move = [[0,0] for _ in range(n+1)]
    for i in range(1,n+1):
        nx, ny = dir(s[i-1])
        move[i] = [move[i-1][0]+nx, move[i-1][1]+ny]
    ans = 10**14+1
    l,r = 0, 10**14+1
    while l <= r:
        mid = (l+r)//2
        week = mid//n
        day = mid%n

        x = x1 + move[day][0] + (week)*move[-1][0]
        y = y1 + move[day][1] + (week)*move[-1][1]

        if abs(x-x2) + abs(y-y2) <= mid:
            ans = min(ans,mid)
            r = mid - 1
        else:
            l = mid + 1
    print([ans,-1][ans==10**14+1])








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
    """sys.setrecursionlimit(400000)
    threading.stack_size(40960000)
    thread = threading.Thread(target=main)
    thread.start()"""
    main()
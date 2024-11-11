import os, sys
from io import BytesIO, IOBase
from math import log2, ceil, sqrt, gcd
from _collections import deque
import heapq as hp
from bisect import bisect_left, bisect_right

from math import cos, sin

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

mod = 10 ** 9 + 7

MX = 101
fact = [1]

for i in range(1, MX):
    fact.append(fact[-1] * i % mod)

inv = [pow(fact[i], mod - 2, mod) for i in range(MX)]


def ncr(n, r):
    if n < 0 or r < 0 or n < r:
        return 0
    return (fact[n] * inv[n - r] * inv[r]) % mod


def dfs(x, par):
    for i in a[x]:
        if i != par:
            ndp[i] = ndp[x] + 1
            ct[-1].append(ndp[i])
            dfs(i, x)



def solve(ck):
    dp1 = [0] * len(ck)

    for i in range(len(ck)):
        dp1[i] = ck[i]
        if i > 0:
            dp1[i] += dp1[i - 1]

    for i in range(2, k + 1):
        ndp1 = [0] * len(ck)
        for j in range(i - 1, len(ck)):
            ndp1[j] = dp1[j - 1] * ck[j]
            ndp1[j] %= mod
        tot = 0
        for j in range(len(ck)):
            tot += ndp1[j]
            tot %= mod
            dp1[j] = tot
    return tot


for _ in range(int(input())):
    input()
    n, k = map(int, input().split())
    a = [[] for _ in range(n + 1)]
    for _ in range(n - 1):
        x, y = map(int, input().split())
        a[x].append(y)
        a[y].append(x)

    ans = 0
    if k == 2:
        print(ncr(n, 2) % mod)
        continue
    for i in range(1, n + 1):
        ndp = [0] * (n + 1)
        ct = []
        for j in a[i]:
            ndp[j]=1
            ct.append([])
            ct[-1].append(1)
            dfs(j,i)

        if len(ct) < k:
            continue
        for j in range(len(ct)):
            ct[j].sort(reverse=True)
        # print('ct ->', ct,i)
        t = 1
        size = len(ct)
        while size >= k:
            ck = []
            for j in range(len(ct)):
                if len(ct[j]):
                    tt = 0
                    while ct[j] and ct[j][-1] == t:
                        tt += 1
                        ct[j].pop()
                    if not ct[j]:
                        size -= 1
                    if tt == 0:
                        continue

                    ck.append(tt)
            # print(ck,ct)
            ans += solve(ck)
            ans%=mod
            t += 1

    print(ans)

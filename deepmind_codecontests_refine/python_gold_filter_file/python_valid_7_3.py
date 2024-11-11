import io
import os

from math import gcd
from collections import namedtuple

StackEntry = namedtuple("StackEntry", ("value", "gcd"))

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


class GCDQueue:
    def __init__(self):
        self.s1 = []
        self.s2 = []

    def gcd(self):
        if self.s1 and self.s2:
            return gcd(self.s1[-1].gcd, self.s2[-1].gcd)
        elif self.s1:
            return self.s1[-1].gcd
        elif self.s2:
            return self.s2[-1].gcd
        else:
            return 0

    def push(self, val):
        g = gcd(val, self.s1[-1].gcd) if self.s1 else val
        self.s1.append(StackEntry(val, g))

    def pop(self):
        if not self.s2:
            while self.s1:
                el = self.s1.pop().value
                g = gcd(el, self.s2[-1].gcd) if self.s2 else el
                self.s2.append(StackEntry(el, g))

        return self.s2.pop()


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    d = [abs(x - y) for x, y in zip(a, a[1:])]

    if n == 1:
        print(1)
        return

    m = 0
    q = GCDQueue()
    l = r = 0
    while l < n - 1:
        while r < n - 1 and gcd(q.gcd(), d[r]) != 1:
            q.push(d[r])
            r += 1
            m = max(m, r - l)
        if r == n - 1:
            break
        q.push(d[r])
        r += 1
        while q.gcd() == 1:
            q.pop()
            l += 1

    print(m + 1)


t = int(input())

for _ in range(t):
    solve()

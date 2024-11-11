from sys import stdin
from bisect import bisect_left as bl
from bisect import bisect_right as br

def input():
    return stdin.readline()[:-1]


def intput():
    return int(input())


def sinput():
    return input().split()


def intsput():
    return map(int, sinput())


class RangedList:
    def __init__(self, start, stop, val=0):
        self.shift = 0 - start
        self.start = start
        self.stop = stop
        self.list = [val] * (stop - start)

    def __setitem__(self, key, value):
        self.list[key + self.shift] = value

    def __getitem__(self, key):
        return self.list[key + self.shift]

    def __repr__(self):
        return str(self.list)

    def __iter__(self):
        return iter(self.list)


def dprint(*args, **kwargs):
    if debugging:
        print(*args, **kwargs)


debugging = 1
# Code
n, m, k = intsput()

starts = []
targets = []

for _ in range(k):
    starts.append(list(intsput()))

for _ in range(k):
    targets.append(list(intsput()))

sol = []
for i in range(m - 1):
    sol.append('L')
for i in range(n - 1):
    sol.append('D')
for i in range(n - 1):
    sol.append('U')

for right in range(m - 1):
    sol.append('R')
    if right % 2:
        for _ in range(n - 1):
            sol.append("U")
    else:
        for _ in range(n - 1):
            sol.append('D')

print(len(sol))
print(''.join(sol))

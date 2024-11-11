import sys


class Bit:
    def __init__(self, n, arr):
        self.size = n
        self.tree = [0] + arr
        for i in range(1, n):
            if i + (i & -i) < n:
                self.tree[i + (i & -i)] += self.tree[i]

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s

    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i

    def range_sum(self, l, r):
        return self.sum(r) - self.sum(l)


def main():
    n, q = map(int, sys.stdin.buffer.readline().split())
    bit = Bit(n, list(map(int, sys.stdin.buffer.readline().split())))
    for x in sys.stdin.buffer.readlines():
        q, p, x = map(int, x.split())
        if q:
            print(bit.range_sum(p, x))
        else:
            bit.add(p+1, x)


if __name__ == "__main__":
    main()

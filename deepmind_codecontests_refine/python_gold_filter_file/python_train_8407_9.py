import sys


class Bit:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i ^= i & -i
        return s

    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i


def main():
    n, q = map(int, sys.stdin.buffer.readline().split())
    bit = Bit(n)
    a = list(map(int, sys.stdin.buffer.readline().split()))
    for i in range(n):
        bit.add(i+1, a[i])
    for x in sys.stdin.buffer.readlines():
        q, p, x = map(int, x.split())
        if q:
            print(bit.sum(x) - bit.sum(p))
        else:
            bit.add(p+1, x)


if __name__ == "__main__":
    main()

from operator import itemgetter
import sys


class BIT:
    def __init__(self, size: int):
        self.size = size + 1
        self.array = [0] * self.size

    def add(self, i, x):
        if not i > 0:
            return
        while i < self.size:
            self.array[i] += x
            i += i & -i

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.array[i]
            i -= i & -i
        return s


def read():
    return sys.stdin.readline().rstrip()


def main():
    n, q = map(int, read().split())
    c = [int(i) for i in read().split()]
    queries = [() for _ in range(q)]
    for i in range(q):
        l, r = map(int, read().split())
        queries[i] = (i, l, r)
    queries.sort(key=itemgetter(2))
    last = [0] * n
    bit = BIT(n)
    ans = [-1] * q
    cr = 0
    for i, l, r in queries:
        for ri in range(cr, r):
            ci = c[ri] - 1
            bit.add(last[ci], -1)
            last[ci] = ri + 1
            bit.add(last[ci], 1)
            cr = ri
        ans[i] = bit.sum(r) - bit.sum(l - 1)
    print(*ans, sep="\n")


if __name__ == '__main__':
    main()

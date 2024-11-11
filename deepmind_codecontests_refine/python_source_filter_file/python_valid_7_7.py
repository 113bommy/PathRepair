from math import gcd
from operator import sub
from sys import stdin, gettrace

if gettrace():
    def inputi():
        return input()
else:
    def input():
        return next(stdin)[:-1]


    def inputi():
        return stdin.buffer.readline()

class IdempotentSparseTable:
    ''' Answer range queries for an idempotent function
    '''
    def __init__(self, data, f):
        '''
        :param data: The data, a list
        :param f: An idempotent function. MUST BE IDEMPOTENT
        '''
        self.f = f
        self.n = len(data)
        self.st = [[d] for d in data]
        k = self.n.bit_length()
        for j in range(1, k):
            for i in range(self.n-(1<<j) + 1):
                self.st[i].append(self.f(self.st[i][j-1], self.st[i + (1 << (j-1))][j-1]))
        self.logs = [0, 0]
        for i in range(2, self.n+1):
            self.logs.append(self.logs[i//2] + 1)

    def range_query(self, l, r):
        j = self.logs[r - l]
        return self.f(self.st[l][j], self.st[r-(1<<j)][j])


def solve():
    n = int(input())
    aa = [int(a) for a in input().split()]
    if n == 1:
        print(1)
        return
    aad = list(map(lambda a, b: abs(a -b), aa, aa[1:]))
    st = IdempotentSparseTable(aad, gcd)
    i = 0
    j = 1
    best = 0
    while j < n:
        if st.range_query(i, j) == 1:
            i += 1
            if j == i:
                j += 1
        else:
            j += 1
            best = max(best, j-i)
    print(best)



def main():
    t = int(input())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()

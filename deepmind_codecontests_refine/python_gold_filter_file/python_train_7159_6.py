from sys import stdin

input = stdin.readline
from collections import defaultdict


class BIT:
    def __init__(self, N):
        self.N = N
        self.arr = [0] * (N + 1)

    def add(self, ind, x=1):
        ind += 1
        while ind <= self.N:
            self.arr[ind] += x
            ind += (ind & -ind)

    def get_sum(self, ind):
        ind += 1
        res = 0
        while ind > 0:
            res += self.arr[ind]
            ind -= (ind & -ind)
        return res


def solve():
    N, Q = map(int, input().split())
    c = list(map(int, input().split()))
    query = [tuple(map(int, inp.split())) for inp in stdin.read().splitlines()]
    prev = [-1] * (N+1)
    nxt = [-1] * (N+1)
    for i, v in enumerate(c):
        if prev[v] != -1:
            nxt[prev[v]] = i
        prev[v] = i
    q = defaultdict(list)
    for i, (l, r) in enumerate(query):
        q[l - 1].append((r - 1, i))
    bit = BIT(N)
    ans = [0] * Q
    for l in range(N - 1, -1, -1):
        if nxt[l] != -1:
            bit.add(nxt[l], 1)
        for r, i in q[l]:
            ans[i] = r - l + 1 - bit.get_sum(r)
    for a in ans:
        print(a)

if __name__ == '__main__':
    solve()

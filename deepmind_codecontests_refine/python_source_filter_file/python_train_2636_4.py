import sys
input = sys.stdin.readline
print = lambda s: sys.stdout.write(s + "\n")
import itertools
import collections
perms = list(itertools.permutations(['A', 'N', 'O', 'T']))

class FenwickTree:
    def __init__(self, n):
        self.t = [0] * (n + 1)

    def update(self, i, x):
        i += 1
        while i < len(self.t):
            self.t[i] += x
            i += i & -i

    def _query(self, r):
        ans = 0
        while r > 0:
            ans += self.t[r]
            r -= r & -r
        return ans
    def query(self, l, r):
        return self._query(r) - self._query(l)

t = int(input())
for _ in range(t):
    s = input().rstrip()
    n = len(s)
    ctr = collections.Counter(s)
    ans = (float('-inf'), None)
    for perm in perms:
        curVal = 0
        curS = []
        firstIdx = {}
        for p in perm:
            startIdx = 0
            for x in curS:
                startIdx += len(x)
            firstIdx[p] = startIdx
            curS.append(p * ctr[p])
        curS = ''.join(curS)

        ft = FenwickTree(n)
        for i, x in enumerate(curS):
            ft.update(i, 1)

        for i, x in enumerate(s):
            curVal += ft.query(i, firstIdx[x])
            ft.update(firstIdx[x], -1)
            firstIdx[x] += 1

        if curVal > ans[0]:
            ans = (curVal, curS)
    print(ans[1])


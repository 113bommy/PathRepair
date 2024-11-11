import sys


class SegTreeMin:

    def __init__(self, n, max_v):
        self.n = n
        n2 = 1
        while n2 < n:
            n2 <<= 1
        self.n2 = n2
        self.tree = [max_v] * (n2 << 1)
        self.INF = max_v

    def update(self, i, x):
        i += self.n2
        self.tree[i] = x
        while i > 1:
            self.tree[i >> 1] = x = min(x, self.tree[i ^ 1])
            i >>= 1

    def get_min(self, a, b):
        result = self.INF
        q = [(1, 0, self.n2)]
        while q:
            k, l, r = q.pop()

            if a <= l and r <= b:
                result = min(result, self.tree[k])
                continue

            m = (l + r) // 2
            k <<= 1
            if a < m and l < b:
                q.append((k, l, m))
            if a < r and l < m:
                q.append((k + 1, m, r))

        return result


def solve():
    input = sys.stdin.readline
    mod = 10 ** 9 + 7
    n, m = list(map(int, input().rstrip('\n').split()))
    seg_tree = SegTreeMin(n, 10 ** 15)
    seg_tree.update(0, 0)
    lrc = [list(map(int, input().rstrip('\n').split())) for _ in range(m)]
    lrc.sort()
    for l, r, c in lrc:
        l -= 1
        r -= 1
        tm = seg_tree.get_min(l, r)
        seg_tree.update(r, min(tm + c, seg_tree.get_min(r, r + 1)))
    mt = seg_tree.get_min(n-1, n)
    print(mt if mt != 10 ** 15 else -1)


if __name__ == '__main__':
    solve()

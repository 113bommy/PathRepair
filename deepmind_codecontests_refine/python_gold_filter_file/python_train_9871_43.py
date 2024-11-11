class SegmentTree:
    def __init__(self, n):
        self.tree = [0] * (2 * n)
        self.n = n

    def modify(self, pos, val):
        tree = self.tree
        pos += self.n
        tree[pos] = val
        while pos > 1:
            tree[pos//2] = max(tree[pos], tree[pos ^ 1])
            pos //= 2

    def query(self, L, R):
        res = 0
        L += self.n
        R += self.n
        while L < R:
            if L % 2 == 1:
                res = max(res, self.tree[L])
                L += 1
            if R % 2 == 1:
                R -= 1
                res = max(res, self.tree[R])

            L //= 2
            R //= 2

        return res


def solve(n, heights, beauty):
    dp = SegmentTree(n+1)
    for h, b in zip(heights, beauty):
        _max = dp.query(0, h)
        dp.modify(h, _max + b)

    return dp.query(0, n+1)


def main():
    n = int(input())
    heights = [int(c) for c in input().split()]
    beauty = [int(c) for c in input().split()]
    ans = solve(n, heights, beauty)
    print(ans)


if __name__ == "__main__":
    main()

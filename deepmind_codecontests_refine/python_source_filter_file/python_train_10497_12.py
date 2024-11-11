import sys
input = sys.stdin.readline

INF = float("inf")


class Acc2D:
    def __init__(self, grid):
        self.h, self.w = len(grid), len(grid[0])
        self.acc2D = self._build(self.h, self.w, grid)

    def _build(self, h, w, grid):
        ret = [[0] * (w + 1) for _ in range(h + 1)]
        for r in range(h):
            for c in range(w):
                ret[r + 1][c + 1] = ret[r][c + 1] + ret[r + 1][c] - ret[r][c] + grid[r][c]
        return ret

    def get(self, r1, r2, c1, c2):
        if r1 < 0:
            r1 = 0
        if r2 >= self.h:
            r2 = self.h
        if c1 < 0:
            c1 = 0
        if c2 >= self.w:
            c2 = self.w
        cnt = self.acc2D
        return cnt[r2][c2] - cnt[r1][c2] - cnt[r2][c1] + cnt[r1][c1]


def main():
    n, k = map(int, input().split())
    g = [[0] * (2 * k) for _ in range(2 * k)]
    for _ in range(n):
        x, y, c = input().split()
        x = int(x) % (2 * k)
        y = int(y) % (2 * k)
        if c == 'B':
            y = (y + k) % (2 * k)
        g[y][x] += 1
    acc2d = Acc2D(g)
    ans = 0
    for r in range(k):
        for c in range(k):
            tmp = acc2d.get(0, r, 0, c)
            tmp += acc2d.get(0, r, c + k, c + k * 2)
            tmp += acc2d.get(r, r + k, c, c + k)
            tmp += acc2d.get(r + k, r + k * 2, 0, c)
            tmp += acc2d.get(r + k, r + k * 2, c + k, c + k * 2)
            ans = max(ans, tmp, n - tmp)
    print(ans)


if __name__ == '__main__':
    main()

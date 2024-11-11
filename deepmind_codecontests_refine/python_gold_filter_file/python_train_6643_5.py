from operator import itemgetter
import sys
input = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 7)

mod = 10 ** 9 + 7


class Combination:
    """
    SIZEが10^6程度以下の二項係数を何回も呼び出したいときに使う
    使い方:
    comb = Combination(SIZE, MOD)
    comb(10, 3) => 120
    """

    def __init__(self, N, MOD=10 ** 9 + 7):
        self.MOD = MOD
        self.fact, self.inv = self._make_factorial_list(N)

    def __call__(self, n, k):
        if k < 0 or k > n:
            return 0
        res = self.fact[n] * self.inv[k] % self.MOD
        res = res * self.inv[n - k] % self.MOD
        return res

    def _make_factorial_list(self, N):
        fact = [1] * (N + 1)
        inv = [1] * (N + 1)
        MOD = self.MOD
        for i in range(1, N + 1):
            fact[i] = (fact[i - 1] * i) % MOD
        inv[N] = pow(fact[N], MOD - 2, MOD)
        for i in range(N, 0, -1):
            inv[i - 1] = (inv[i] * i) % MOD
        return fact, inv


def main():
    H, W, N = map(int, input().split())
    XY = list(tuple(map(int, input().split())) for _ in range(N))

    comb = Combination(H + W + 10, mod)
    fact = tuple(comb.fact)
    inv = tuple(comb.inv)

    edge = [[] for _ in range(N + 2)]
    indeg = {i: 0 for i in range(N + 2)}

    edge[0].append((N + 1, comb(H+W-2, H-1)))
    indeg[N + 1] += 1
    for i, (x1, y1) in enumerate(XY, 1):
        # start->i
        edge[0].append((i, comb(x1+y1-2, x1-1)))
        indeg[i] += 1
        # i->goal
        edge[i].append((N + 1, comb(H+W-x1-y1, H-x1)))
        indeg[N + 1] += 1
        for j, (x2, y2) in enumerate(XY, 1):
            if i == j:
                continue
            if x1 <= x2 and y1 <= y2:
                edge[i].append((j, comb(x2+y2-x1-y1, x2-x1)))
                indeg[j] += 1

    order = sorted(indeg.items(), key=itemgetter(1))
    dp = [0] * (N + 2)
    dp[0] = -1
    for s, _ in order:
        for t, path in edge[s]:
            dp[t] = (dp[t] - path * dp[s] + mod) % mod
    print(dp[N + 1])


if __name__ == "__main__":
    main()
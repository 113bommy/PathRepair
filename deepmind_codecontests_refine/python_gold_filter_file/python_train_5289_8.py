import sys
stdin = sys.stdin

sys.setrecursionlimit(10 ** 7)

def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x) - 1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

class CombTools(object):
    def __init__(self, cap: int, mod: int):
        self.cap = cap
        self.mod = mod
        self.inv = self._calc_inv()
        self.fac = self._calc_fac()
        self.fac_inv = self._calc_fac_inv()

    def _calc_inv(self):
        inv = [0, 1]
        for i in range(2, self.cap+1):
            inv.append((self.mod - (self.mod // i) * inv[self.mod % i]) % self.mod)

        return inv

    def _calc_fac(self):
        fac = [1]
        for i in range(1, self.cap+1):
            fac.append((i * fac[-1]) % self.mod)

        return fac

    def _calc_fac_inv(self):
        fac_inv = [1]
        for i in range(1, self.cap+1):
            fac_inv.append((self.inv[i] * fac_inv[-1]) % self.mod)

        return fac_inv

    def nCr(self, n: int, r: int):
        # validation
        if r > n:
            raise ValueError("n must be larger than r (n={}, r={})".format(n, r))

        # calculation
        return self.fac[n] * self.fac_inv[n-r] * self.fac_inv[r] % self.mod


class BIT(object):
    def __init__(self, n: int):
        self.bitree = [0]*(pow(2, (n-1).bit_length()) + 1)
        self.size = len(self.bitree) - 1

    def add(self, index, value):
        while index <= self.size:
            self.bitree[index] += value
            index += (-index) & index

    def get(self, index):
        ans = 0
        while index > 0:
            ans += self.bitree[index]
            index -= (-index) & index

        return ans


# 入力
n = ni()
xs = []
ys = []
ps = []
MOD = 998244353
for _ in range(n):
    xi, yi = li()
    xs.append(xi)
    ys.append(yi)
    ps.append([xi, yi])

# 座標圧縮
xcomp = {xi: i+1 for i, xi in enumerate(sorted(xs))}
ycomp = {yi: i+1 for i, yi in enumerate(sorted(ys))}
pcomp = [[xcomp[xi], ycomp[yi]] for xi, yi in zip(xs, ys)]
pcomp.sort()

# 答え
ans = 0

# 自分が選択される
ct = CombTools(n, MOD)
for i in range(1,n+1):
    ans += i * ct.nCr(n, i)
    ans %= MOD

# BITで左右管理
leftBIT = BIT(n)
rightBIT = BIT(n)

for _, yi in pcomp:
    rightBIT.add(yi, 1)

# 左端から繰り返し
pow2 = [pow(2, i, MOD) for i in range(n+1)]
for _, yi in pcomp:
    rightBIT.add(yi, -1)

    nw = leftBIT.get(n) - leftBIT.get(yi)
    ne = rightBIT.get(n) - rightBIT.get(yi)
    sw = leftBIT.get(yi)
    se = rightBIT.get(yi)

    ans += (pow2[nw] - 1) * (pow2[se] - 1) * (pow2[ne] * pow2[sw])
    ans += (pow2[sw] - 1) * (pow2[ne] - 1) * (pow2[se] * pow2[nw])
    ans -= (pow2[nw] - 1) * (pow2[ne] - 1) * (pow2[sw] - 1) * (pow2[se] - 1)
    ans %= MOD

    leftBIT.add(yi, 1)

print(ans)
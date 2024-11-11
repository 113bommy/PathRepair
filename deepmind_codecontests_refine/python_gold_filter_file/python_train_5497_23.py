MOD = 10**9 + 7
class mint:
    def __init__(self, i):
        self.i = i
    def __add__(self, m):
        t = self.i + (m.i if isinstance(m, mint) else m)
        if t > MOD:
            t -= MOD
        return mint(t)
    def __radd__(self, m):
        t = self.i + (m.i if isinstance(m, mint) else m)
        if t > MOD:
            t -= MOD
        return mint(t)
    def __mul__(self, m):
        return mint(self.i * (m.i if isinstance(m, mint) else m) % MOD)
    def __sub__(self, m):
        t = self.i - (m.i if isinstance(m, mint) else (m % MOD))
        if t < 0:
            t += MOD
        return mint(t)
    def __pow__(self, m):
        i = self.i
        return mint(pow(i, m, MOD))
    def __truediv__(self, m):
        return mint(self.i * pow(m, MOD - 2, MOD) % MOD)
    def __repr__(self):
        return repr(self.i)


n, k = map(int, input().split())

l, r = 1, n + 1
while r - l > 1:
    c = (l + r) // 2
    if c ** 2 <= n:
        l = c
    else:
        r = c
r = l # less than or equal to sqrt(n)
# 1 ... r - 1, r, (r, n/r], ... (n/3, n/2], (n/2, n]
# (a, b] ... count for each elem in (a, b], not sum
# (r, n/r] is ignored if r*r == n
dp = [mint(0) for _ in range(2 * r)]
dp[0] = mint(1)
for _ in range(k):
    ndp = [mint(0) for _ in range(2 * r)]
    for i in range(1, r + 1):
        pre_cnt = dp[i - 1]
        if i == r and r ** 2 == n:
            ndp[r - 1] += pre_cnt
        else:
            ndp[-i] += pre_cnt
    for i in range(1, r + 1):
        if i == r and r ** 2 == n:
            continue
        pre_cnt = dp[-i]
        upper = n // i
        lower = r + 1 if i == r else 1 + n // (i + 1)
        ndp[i - 1] += pre_cnt * (upper - lower + 1)
    acc = mint(0)
    for i in range(r * 2 - 1, -1, -1):
        if i == r and r ** 2 == n:
            continue
        acc += ndp[i]
        dp[i] = acc

ans = mint(0)
for i in range(1, r + 1):
    ans += dp[i - 1]
for i in range(1, r + 1):
    upper = n // i
    lower = r + 1 if i == r else 1 + n // (i + 1)
    ans += dp[-i] * (upper - lower + 1)
print(ans)

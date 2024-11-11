class Combination:
    def __init__(self, size, mod=10**9 + 7):
        self.size = size + 2
        self.mod = mod
        self.fact = [1, 1] + [0] * size
        self.factInv = [1, 1] + [0] * size
        self.inv = [0, 1] + [0] * size

        for i in range(2, self.size):
            self.fact[i] = self.fact[i - 1] * i % self.mod
            self.inv[i] = -self.inv[self.mod % i] * (self.mod // i) % self.mod
            self.factInv[i] = self.factInv[i - 1] * self.inv[i] % self.mod

    def npr(self, n, r):
        if n < r or n < 0 or r < 0:
            return 0
        return self.fact[n] * self.factInv[n - r] % self.mod

    def ncr(self, n, r):
        if n < r or n < 0 or r < 0:
            return 0
        return self.fact[n] * (self.factInv[r] * self.factInv[n - r] % self.mod) % self.mod

    def nhr(self, n, r):  # 重複組合せ
        return self.ncr(n + r - 1, n - 1)

    def factN(self, n):
        if n < 0:
            return 0
        return self.fact[n]

N = int(input())
MOD = 10**9 + 7
comb = Combination(N + 100)

edges = [[] for _ in range(N + 1)]
for _ in range(N - 1):
    fr, to = map(int, input().split())
    edges[fr].append(to)
    edges[to].append(fr)

parent = [0] * (N + 1)
order = []
st = [1]
while st:
    now = st.pop()
    order.append(now)
    for to in edges[now]:
        if to == parent[now]:
            continue
        st.append(to)
        parent[to] = now

size = [1] * (N + 1)
for v in order[::-1]:
    size[parent[v]] += size[v]

dp = [1] * (N + 1)
for v in order[::-1]:
    dp[v] = dp[v] * comb.fact[size[v] - 1] % MOD
    dp[parent[v]] *= dp[v] * comb.factInv[size[v]]

ans = [1] * (N + 1)
dpL = [[] for _ in range(N + 1)]
dpR = [[] for _ in range(N + 1)]
eToI = [{to: i for i, to in enumerate(edges[v])} for v in range(N + 1)]

for v in order:
    pr = parent[v]
    M = len(edges[v])
    L = [1] * (M + 1)
    R = [1] * (M + 1)

    for i, to in enumerate(edges[v]):
        if to == pr:
            j = eToI[pr][v]
            L[i + 1] = L[i] * dpL[pr][j] * dpR[pr][j + 1] * comb.fact[N - size[v] - 1] * comb.factInv[N - size[v]] % MOD
        else:
            L[i + 1] = L[i] * dp[to] * comb.factInv[size[to]] % MOD
    for i, to in enumerate(edges[v][::-1]):
        if to == pr:
            j = eToI[pr][v]
            R[i + 1] = R[i] * dpL[pr][j] * dpR[pr][j + 1] * comb.fact[N - size[v] - 1] * comb.factInv[N - size[v]] % MOD
        else:
            R[i + 1] = R[i] * dp[to] * comb.factInv[size[to]] % MOD

    dpL[v] = L
    dpR[v] = R[::-1]
    ans[v] = R[-1] * comb.fact[N - 1] % MOD

print(*ans[1:], sep='\n')
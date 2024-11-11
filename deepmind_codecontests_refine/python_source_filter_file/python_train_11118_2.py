from itertools import product
L, R = map(int, input().split())
MOD = 10**9 + 7

dp = [[[0, 0] for _ in range(2)] for _ in range(2)]
pp = [[[0, 0] for _ in range(2)] for _ in range(2)]
dp[0][0][0] = 1
for d in range(60, -1, -1):
    pp, dp = dp, pp
    dp = [[[0, 0] for _ in range(2)] for _ in range(2)]
    lb = L>>d & 1
    rb = R>>d & 1
    if d == 1:
        pass
    ans = 0
    for lrs in product((0,1), repeat=3):
        l, r, s = lrs
        for xy in product((0,1), repeat=2):
            nl, nr, ns = l, r, s
            x, y = xy
            if x and not y:
                continue
            if not s and x != y:
                continue
            if x and y:
                ns = 1
            if not l and not x and lb:
                continue
            if x and not lb:
                nl = 1
            if not r and y and not rb:
                continue
            if not y and rb:
                nr = 1
            dp[nl][nr][ns] += pp[l][r][s]
            dp[nl][nr][ns] %= MOD

print(sum(dp[l][r][s] for l in (0,1) for r in (0,1) for s in (0,1)))

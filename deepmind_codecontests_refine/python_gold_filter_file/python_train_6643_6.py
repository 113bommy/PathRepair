h, w, n = map(int, input().split())
wall = [list(map(int, input().split())) for _ in range(n)]

wall.sort(key=lambda x: x[1])
wall.sort(key=lambda x: x[0])


# combination---

mod = 10**9 + 7
fac = [1, 1]
inv = [1, 1]
finv = [1, 1]
for i in range(2, h+w+1):
    fac.append(fac[i-1] * i % mod)
    inv.append(mod - inv[mod%i] * (mod//i) % mod)
    finv.append(finv[i-1] * inv[i] % mod)

def nck(n, k):
    if n < k:
        return 0
    if n < 0 or k < 0:
        return 0
    return fac[n] * (finv[k] * finv[n-k] % mod) % mod



# dp[i]:= i-1番目までの壁を通らず、i番目の壁にたどり着く経路の数
dp = [0] * n

for i in range(n):
    res = 0    # i-1までの壁を一回以上通って、i回目の壁にたどり着く経路数
    for j in range(i):
        # 最初にぶつかる壁がjで、iの壁に到達する経路数を求めていく
        res += dp[j] * nck(wall[i][0] - wall[j][0] + wall[i][1] - wall[j][1], wall[i][0] - wall[j][0])
        res %= mod
        
    # dp[i] = (i番目の壁までの経路数) - (i-1までの壁を一回以上通って、i回目の壁にたどり着く経路数)
    dp[i] = nck(wall[i][0] - 1 + wall[i][1] - 1, wall[i][0] - 1) - res
    dp[i] %= mod

# 余事象 ((h, w)までに少なくとも1つの壁にぶつかる経路数を数える)
ans = 0
for i in range(n):
    # 最初にぶつかる壁がiで、(h, w)に到達する経路数
    ans += dp[i] * nck(h - wall[i][0] + w - wall[i][1], h - wall[i][0])
    ans %= mod

print((nck(h-1 + w-1, h-1) - ans) % mod)
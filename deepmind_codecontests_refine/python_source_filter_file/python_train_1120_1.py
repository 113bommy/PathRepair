n, k = map(int, input().split())
mod = 998244353
list_s = []
for _ in range(k):
    l, r = map(int, input().split())
    list_s.append((l, r))
dp = [0] * (n + 1)
sdp = [0] * (n + 1)
dp[1] = 1
sdp[0] = 0
sdp[1] = 1

for i in range(2, n + 1):
    for l, r in list_s:
        dl = max(0, i - r - 1)
        dr = max(0, i - l)
        dp[i] += sdp[dr] - sdp[dl]
        sdp[i] = sdp[i - 1] + dp[i]
print(dp[n] % mod)
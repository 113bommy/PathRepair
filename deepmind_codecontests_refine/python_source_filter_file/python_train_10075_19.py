mod = 998244353

n, s = map(int, input().split())
a = list(map(int, input().split()))

a.sort()

while a[-1] > s:
    a.pop(-1)
    if a == []:
        print(0)
        exit()

dp = [0] * (s + 1)
dp[0] = 1
for i in a:
    newdp = [2 * j % mod for j in dp]
    for j in range(s - i + 1):
        newdp[j+i] += dp[j]
    dp = newdp

print(dp[s] * pow(2, n - len(a), mod) % mod)
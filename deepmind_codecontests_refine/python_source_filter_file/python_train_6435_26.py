MOD = 10 ** 9 + 7
k = input()
d = int(input())
dp = [0] * d
now = 0
for i in map(int, k):
    ndp = [0] * d
    for t in range(i):
        ndp[(now+t) % d] = (ndp[(now+t) % d] + 1) % MOD
    for j in range(d):
        for t in range(10):
            ndp[(j+t) % d] = (ndp[(j+t) % d] + dp[j]) % MOD
    now = (now + i) % d
    dp = ndp
print(dp[0] - 1 + (now == 0))
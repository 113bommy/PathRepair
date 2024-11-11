k = input()
d = int(input())

MOD = 10**9 + 7

k_len = len(k)
dp = [[0] * d for _ in range(k_len)]
dp[0][0] = 1

# if( k_len == 1 ):
#     k = int(k)
#     print(k//d)
#     exit()
#
# for i in range(10):
#     dp[0][i%d] += 1

for i in range(1, k_len):
    for j in range(10):
        dp[i][0] += dp[i-1][(0-j)%d]
    dp[i][0] = dp[i][0] % MOD
    for j in range(1,d):
        dp[i][j] = (dp[i][j-1] + dp[i-1][j] - dp[i-1][(j-10)%d]) % MOD

ans = 0
heads = 0
for i in range(k_len):
    pick = int(k[i])
    for j in range(pick):
        ans += dp[k_len - 1 - i][(0 - j - heads) % d]
        ans = ans % MOD
    heads += pick

if(heads % d == 0):
    ans += 1

print((ans - 1)%MOD)

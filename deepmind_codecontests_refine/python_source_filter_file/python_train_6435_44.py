k = input()
d = int(input())
MOD = 10**9 + 7

# dp[i][is_smaller][summation % d]
dp = [[[0]*d for i in range(2)] for i in range(len(k)+1)]
dp[0][0][0] = 1

for i in range(len(k)):
    # is_smaller = 0 -> is_smaller = 0
    for l in range(d):
        dp[i+1][0][(l+int(k[i])) % d] += dp[i][0][l]
        dp[i+1][0][(l+int(k[i])) % d] %= MOD
        
    # is_smaller = 0 -> is_smaller = 1
    for l in range(d):
        for j in range(int(k[i])):
            dp[i+1][1][(l+j) % d] += dp[i][0][l]            
            dp[i+1][1][(l+j) % d] %= MOD    

    # is_smaller = 1 -> is_smaller = 1
    for l in range(d):
        for j in range(10):
            dp[i+1][1][(l+j) % d] += dp[i][1][l]
            dp[i+1][1][(l+j) % d] %= MOD

print(dp[len(k)][1][0] + dp[len(k)][0][0] - 1)
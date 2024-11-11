k = str(input())
d = int(input())
 
l = len(k)
 
mod = 10 ** 9 + 7
 
#less than: 1, else: 0
dp = [[[0] * 2 for _ in range(d)] for i in range(l+1)]
dp[0][0][0] = 1
 
for i in range(l):
    lim = int(k[i])
    for j in range(d):
        for num in range(10):
            dp[i+1][(j+num) % d][1] = (dp[i+1][(j+num) % d][1] + dp[i][j][1]) % mod
        for num in range(lim):
            dp[i+1][(j+num) % d][1] = (dp[i+1][(j+num) % d][1] + dp[i][j][0]) % mod
        
        dp[i+1][(j+lim) % d][0] = (dp[i+1][(j+lim) % d][0] + dp[i][j][0]) % mod
                
ans = (dp[l][0][0] + dp[l][0][1] + mod - 1) % mod
 
print(ans)
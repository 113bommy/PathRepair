n,l,r = map(int,input().strip().split())
dp = [[0 for x in range(3)] for j in range(n+1)]
start = l % 3;
mod = 10**9 + 7;
if start == 0:
    one = (r - l)// 3 + 1
    two = (r -l - 1)//3 + 1 if r >= l +1 else 0 ;
    three = (r - l - 2) // 3 + 1 if r >= l + 2 else 0;
elif start == 1:
    two = (r-l) // 3 + 1;
    three = (r - l - 1) // 3 + 1 if r >= l + 1 else 0;
    one = (r - l - 2) // 3 + 1 if r >= l + 2 else 0;
else:
    three= (r - l) // 3 + 1;
    one = (r - l - 1) // 3 + 1 if r >= l + 1 else 0;
    two = (r - l - 2) // 3 + 1 if r >= l + 2 else 0;
for x in range(3):
    dp[1][0] = one
    dp[1][1] = two
    dp[1][2] = three
for x in range(2,n+1):
        dp[x][0] = dp[x-1][0] * dp[1][0] + dp[x-1][1] * dp[1][2] + dp[x-1][2] * dp[1][1]  % mod;
        dp[x][1] = dp[x-1][0] * dp[1][1] + dp[x-1][1] * dp[1][0] + dp[x-1][2] * dp[1][2] % mod;
        dp[x][2] = dp[x-1][0] * dp[1][2] + dp[x-1][1] * dp[1][1] + dp[x-1][2] * dp[1][0] % mod;
print(dp[n][0])


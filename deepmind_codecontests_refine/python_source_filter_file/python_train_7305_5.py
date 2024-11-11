t = int(input())

def solve():
    n,a,b = map(int,input().split())
    dp = [[10**10,10**10] for i in range(n + 1)]
    dp[0][0] = b
    s = input()
    s += '0'
    for i in range(1,n + 1):
        if s[i] == '1':
            dp[i][1] = min(dp[i - 1][0] + 2*a + 2*b, dp[i - 1][1] + a + 2*b)
        elif s[i - 1] != '1':
            dp[i][0] = min(dp[i - 1][0] + a + b, dp[i - 1][1] + 2*a + b)
            dp[i][1] = min(dp[i - 1][0] + 2*a + 2*b, dp[i - 1][1] + a + 2*b)
        else:
             dp[i][1] = dp[i - 1][1] + a + 2*b

    print(dp[n][0])



for i in range(t):
    solve()
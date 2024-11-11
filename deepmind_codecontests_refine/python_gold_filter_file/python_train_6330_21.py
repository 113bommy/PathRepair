Q = 998244353
N = int( input())
A = [ int( input()) for _ in range(N)]
S = sum(A)
H = (S+1)//2
dp = [0]*(S+1)
dp[0] = 1
for a in A:
    for s in range(S, a-1, -1):
        dp[s] = (dp[s]*2 + dp[s-a])%Q
    for s in range(a-1,-1,-1):
        dp[s] = dp[s]*2%Q
ans = (pow(3, N, Q) - sum(dp[H:])%Q*3%Q)%Q
if S%2 == 0:
    dp = [0]*(S+1)
    dp[0] = 1
    for a in A:
        for s in range(S,a-1,-1):
            dp[s] = (dp[s] + dp[s-a])%Q
    ans += dp[H]*3
    ans %= Q
print(ans)
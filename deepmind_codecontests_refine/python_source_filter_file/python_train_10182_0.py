n = int(input())
ga, sa, ba = map(int, input().split())
gb, sb, bb = map(int, input().split())
dp = [0] * (n + 1)
for i in range(n):
    if i + ga <= n:
        dp[i + ga] = max(dp[i + ga], dp[i] + gb)
    if i + sa <= n:
        dp[i + sa] = max(dp[i + sa], dp[i] + sb)
    if i + ba <= n:
        dp[i + ba] = max(dp[i + ba], dp[i] + bb)
ans = 0
for i in range(n + 1):
    ans = max(ans, dp[i] + n - i)
p = min(25000024, ans)
dp = [0] * (p + 1)
for i in range(p):
    if i + gb <= p:
        dp[i + gb] = max(dp[i + gb], dp[i] + ga)
    if i + sb <= p:
        dp[i + sb] = max(dp[i + sb], dp[i] + sa)
    if i + bb <= p:
        dp[i + bb] = max(dp[i + bb], dp[i] + ba)
res = 0
for i in range(p + 1):
    res = max(ans, dp[i] + ans - i)
print(ans)

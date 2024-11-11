n = int(input())
a = sorted(list(map(int, input().split())))

x = max(a)
dp = [0] * x
for ai in a:
    i = 1
    while i * ai <= x:
        dp[i * ai - 1] += 1
        i += 1

ans = 0
for ai in a:
    if dp[ai-1] <= 1:
        ans += 1

print(ans)
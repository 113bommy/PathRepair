l = int(input())
a = [int(input()) for _ in range(l)]

dp = [[0 for i in range(5)] for j in range(l+1)]

def cost(s, a):
    if s == 0 or s == 4:
        return a
    elif s == 1 or s == 3:
        if a > 0:
            return a%2
        else:
            return 2
    else:
        return (a+1)%2

for i in range(l):
    dp[i+1][0] = min(dp[i][:1]) + cost(0, a[i])
    dp[i+1][1] = min(dp[i][:2]) + cost(1, a[i])
    dp[i+1][2] = min(dp[i][:3]) + cost(2, a[i])
    dp[i+1][3] = min(dp[i][:4]) + cost(3, a[i])
    dp[i+1][4] = min(dp[i][:5]) + cost(4, a[i])

print(min(dp[l]))


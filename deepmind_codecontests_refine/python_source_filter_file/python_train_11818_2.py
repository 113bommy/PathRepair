n = int(input())
a = [0] * (10**6+5)
dp = [0] * (10**6+5)
maxx = -1
for i in range(n):
    b, c = map(int, input().split())
    a[b] = c
for i in range(len(a)):
    if i == 0:
        if a[0] == 0:
            dp[0] = 1
    elif a[i] == 0:
        dp[i] = dp[i-1]
    elif a[i] >= i:
        dp[i] = 1
    else:
        dp[i] = dp[i-a[i]-1]+1
    if dp[i] > maxx:
        maxx = dp[i]
print(n-maxx)
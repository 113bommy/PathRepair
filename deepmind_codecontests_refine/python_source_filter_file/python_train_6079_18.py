s = input()
m = int(input())
n = len(s)
dp = [0] * (n + 2)
pr = []
for i in range(1, n):
    if s[i] == s[i - 1]:
        dp[i] = dp[i - 1] + 1
    else:
        dp[i] = dp[i - 1]
for i in range(m):
    o = input().split()
    l = int(o[0])
    r = int(o[1])
    p = dp[r - 1] - dp[l - 2]
    if s[l - 2] == s[l - 1] and l != 1:
        p -= 1
    pr += str(p)
print('\n'.join(pr))


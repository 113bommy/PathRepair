import sys
input = sys.stdin.readline

dp = []
M = 10 ** 9 + 7
for i in range(200011):
    if i < 10:
        dp.append(1)
    else:
        dp.append((dp[i - 9] + dp[i - 10]) % M)

for _ in range(int(input())):
    n, m = input().split()
    m = int(m)

    ans = 0
    for i in n:
        ans += dp[m + int(i)] % M
    print(ans)
def div(n, d):
    cnt = 0
    while n % d == 0 and cnt < 18:
        n //= d
        cnt += 1
    return cnt


n = int(input())
dp = [[0]*19 for _ in range(19)]

ans = 0
for _ in range(n):
    x = round(float(input())*10**9)
    two = div(x, 2)
    five = div(x, 5)
    ans += dp[18 - two][18 - five]
    for i in range(two + 1):
        for j in range(five + 1):
            dp[i][j] += 1

print(ans)
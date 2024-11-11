[n, l, r] = [int(i) for i in input().split(" ")]

answer = 1
mod = []
if l == r:
    if (n * l) % 3 == 0:
        answer = 0
else:
    surplus = (r - l + 1) % 3
    mod = [int((r - l + 1 - surplus) / 3)] * 3
    if surplus == 1:
        mod[r % 3] += 1
    if surplus == 2:
        mod[r % 3] += 1
        mod[(r - 1) % 3] += 1
    dp = [([0] * (n + 1)) for i in range(3)]
    
    dp[0][0] = 1
    for i in range(1, n+1):    
        for j in range(3):
            dp[j][i] = (dp[j][i - 1] * mod[0] + dp[(j + 1)%3][i - 1] * mod[2] + dp[(j + 2)%3][i - 1] * mod[1]) % (1000000007)
    
    answer = dp[0][n]
print(answer)
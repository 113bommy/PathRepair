# input
n = int(input())

mod = pow(10, 9) + 7
c = []
dp = [0] * (n + 1)
stone_history = dict()
for i in range(n):
    stone = int(input())
    if len(c) == 0:
        dp[i + 1] = 1
    else:
        if stone in stone_history and c[-1] != stone:
            dp[i + 1] = dp[i] + stone_history[stone]
        else:
            dp[i + 1] = dp[i]

    stone_history[stone] = dp[i + 1]
    c.append(stone)

print(dp[-1] % mod)

K = list(map(int, input()))
D = int(input())

mod = 10 ** 9 + 7

next_dp = [0] * D
border = 0

for current_digit in K:
    dp, next_dp = next_dp, [0] * D
    for current_mod, cnt in enumerate(dp):
        for next_mod in range(current_mod, current_mod + 10):
            next_dp[next_mod % D] += cnt

    for next_mod in range(border, current_digit + border):
        next_dp[next_mod % D] += 1

    border = (border + current_digit) % D

    for i in range(D):
        next_dp[i] %= mod
print((next_dp[0] + (border == 0) - 1) % mod)

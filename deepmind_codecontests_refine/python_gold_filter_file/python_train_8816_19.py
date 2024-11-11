MOD = 10 ** 9 + 7

x, k = map(int, input().split())

if not x:
    print(0)
else:
    two_power_k = pow(2, k, MOD)
    answer = (two_power_k * 2 * x) - two_power_k + 1
    print(answer % MOD)

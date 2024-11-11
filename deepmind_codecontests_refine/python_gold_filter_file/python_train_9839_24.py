def solve(x):
    classic_sum = (1 + x) * x // 2

    pow_sum = 0
    tmp = 1
    while tmp <= x:
        pow_sum += tmp
        tmp *= 2

    return classic_sum - (2 * pow_sum)


n = int(input())

for i in range(n):
    print(solve(int(input())))

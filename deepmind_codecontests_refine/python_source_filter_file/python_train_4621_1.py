
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]
dp = [[-1 for i in range(12)] for i in range(1100)]


def solve(divisors, index):
    if (divisors == 1):
        return 1
    if (index == 11):
        return 9999999999999999999999999999
    if dp[divisors][index] != -1:
        return dp[divisors][index]

    ans = 9999999999999999999999999999
    for i in range(2, divisors + 1):
        if (divisors % i == 0):

            temp = solve(divisors // i, index + 1) * (primes[index] ** (i - 1))
            ans = min(ans, temp)

    dp[divisors][index] = ans
    return dp[divisors][index]


n = int(input())
print(solve(118, 0))

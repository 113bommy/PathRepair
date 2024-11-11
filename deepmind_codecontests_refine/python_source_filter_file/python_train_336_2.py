def factorial(n, mod):
    res = 1
    for i in range(1, n + 1):
        res *= i
        res %= mod
    return res
n = int(input())
mod = 1000000007
print(factorial(n, mod) - pow(2, n - 1, mod))
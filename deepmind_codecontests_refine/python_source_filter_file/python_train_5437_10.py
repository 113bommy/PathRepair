from math import factorial
m, n = map(int, input().split())
print((factorial(2 * m + n - 1) / factorial(2 * m) / factorial(n - 1)) % (10 ** 9 + 7))


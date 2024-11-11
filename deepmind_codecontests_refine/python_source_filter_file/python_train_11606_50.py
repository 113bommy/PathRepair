from math import factorial

n = int(input())
m = factorial(2 * n) // (factorial(n) ** 2)

print(m)
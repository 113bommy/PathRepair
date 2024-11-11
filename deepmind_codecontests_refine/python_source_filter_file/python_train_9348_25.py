from math import factorial

n, k = map(int, input().split())
def fac(n, r):
    return factorial(n) // (factorial(n - r) * factorial(r))
for i in range(1, k + 1):
    print( (fac(n - k + 1, i) * fac(k - 1, i - 1)) % (10 ** 9 + 7))

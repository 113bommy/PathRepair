from math import sqrt

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

x = int(input())
ma = 1
for i in range(2, int(sqrt(x)) + 1):
    if x % i == 0 and i * (x // i) // gcd(i, x // i):
        ma = i
print(ma, x // ma)
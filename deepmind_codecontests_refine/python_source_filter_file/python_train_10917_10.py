import sys
def gcd(a, b):
    for i in range(1, a):
        if a % i == 0:
            t = a // i
            if b % t == 0:
                return t
for line in sys.stdin:
    a, b = sorted(map(int, line.split()))
    gcdab = gcd(a, b)
    print(gcdab, a // gcdab * b)
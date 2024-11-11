import fractions

A, B = map(int, input().split())

print((x * y) // fractions.gcd(x, y))
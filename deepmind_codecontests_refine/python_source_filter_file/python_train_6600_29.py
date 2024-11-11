from fractions import Fraction

a, b, c, d = map(int, input().split())
x, y = a * d, b * c
z = Fraction((max(x, y) - min(x, y)), max(x, y))
if float(z) == 0:
    print(0)
else:
    print(z)

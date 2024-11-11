from sys import stdin
from fractions import Fraction

(a,b,c,d) = map(int, input().split());

cd = Fraction(c, d)
ab = Fraction(a, b)
f1 = Fraction(1, 1)

if cd < ab:
	print(f1 - Fraction(c * b, a * d))
elif cd > ab:
	print(f1 - Fraction(a * d, c * b))
else:
	print("0/1")
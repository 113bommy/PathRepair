from fractions import *

x, y, k = map(int, input().split())
ans = Fraction(x/y).limit_denominator(k)
print(str(ans.numerator)+"/"+str(ans.denominator))

from math import gcd
from fractions import Fraction
def reduce_fraction(x,y):
    d = gcd(x,y)
    x = x // d
    y = y // d
    frac = Fraction(x/y).limit_denominator()
    print (frac)

a,b,c,d = map(int,input().split())
horizontal_space = (b*c - a*d) 
vertical_space = (a*d - b*c)
flag = False
if horizontal_space == vertical_space:
    print("0")
    flag = True
elif horizontal_space > 0:
    numerator = horizontal_space
    denominator = b*c
elif vertical_space > 0:
    numerator = vertical_space
    denominator = a*d

if not flag:
    reduce_fraction(numerator , denominator)


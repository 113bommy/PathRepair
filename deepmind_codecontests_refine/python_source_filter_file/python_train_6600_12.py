from fractions import Fraction
a,b,c,d = map(int,input().split())
r = min(c/a, d/b)
a = a*r
b = b*r
if(c*d - a*b) == 0:
    print(0)
else:
    print(Fraction((c*d-a*b)/(c*d)).limit_denominator())


from fractions import Fraction
x,y,n=map(int,input().split())
v=Fraction(x/y).limit_denominator(n)
print(v.numerator,v.denominator,sep='/')
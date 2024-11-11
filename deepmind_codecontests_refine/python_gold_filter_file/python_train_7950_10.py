from fractions import Fraction
x,y,n=map(int,input().split())
z=Fraction(x,y).limit_denominator(n)
print(z.numerator,z.denominator,sep='/')


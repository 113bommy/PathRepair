from fractions import *
from math import *
# while True:
t, w, b = map(int, input().split())
d = w*b//gcd(w, b)
e = min(w, b)
f = ~-(t-e+1)//d+1
g = min(e, max(0, t-f*d+1))
n = Fraction(max(0, f*e)+g-1, t)
print(f, g)
print(f"{n.numerator}/{n.denominator}")

# t-e+1
'''
10 3 2 =3/10
7 1 2  =3/7
15 3 5 =1/5
16 3 5 =1/4
17 3 5 =5/17
18 3 5 =5/18
1 2 3  =1/1
'''

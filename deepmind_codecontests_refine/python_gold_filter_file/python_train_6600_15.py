from fractions import  Fraction as f
a,b,c,d=map(int,input().split())
if f(a,b)<f(c/d):
    print(f(b-(a*f(d,c)),b))
elif f(a,b)>f(c/d):
    print(f(a-(c*(f(b,d))),a))
else:
    print('0/1')
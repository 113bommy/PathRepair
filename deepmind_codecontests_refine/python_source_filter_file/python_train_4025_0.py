def f(a,b):
    if  a % b == 0:
        return a // b
    else:
        return a // b + 1

hh,mm = map(int,input().split())
h,d,c,n = map(int,input().split())
t = hh * 60 + mm
if t > 20 * 60:
    print(c * f(h,n))
else:
    print(min(c * f(h,n),c * 0.8 * f((20 * 60 - t) * d + h,n) ))
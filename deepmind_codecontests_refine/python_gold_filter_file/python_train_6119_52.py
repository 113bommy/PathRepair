from math import gcd
x = int(input())
print((x*360)//gcd(x,360)//x)
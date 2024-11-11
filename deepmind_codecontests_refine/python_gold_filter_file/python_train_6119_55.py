from math import gcd
x = int(input())
print(360*(x//gcd(x,360))//x)
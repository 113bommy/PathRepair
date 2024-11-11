x,y,a,b = map(int,input().split())
def lcm(a,b):
    from math import gcd
    return a*b//gcd(a,b)
z = lcm(x,y)
print(b//z-a//z + 1)

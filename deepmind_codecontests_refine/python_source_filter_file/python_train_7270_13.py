from fractions import gcd
def lcm(a,b):
    return a*b//gcd(a,b)
n=int(input())
s=1
for i in range(n):
    t=int(input())
    s=lcm(a,t)
print(s)
from fractions import gcd
a=1
for _ in[0]*int(input()):
    t=int(input())
    a*=t//gcd(a,t)
print(a)

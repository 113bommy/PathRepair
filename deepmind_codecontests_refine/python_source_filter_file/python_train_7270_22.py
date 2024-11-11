from fractions import gcd
l=1
for _ in[0]*int(input()):
    t=int(input())
    l=gcd(l,t)
print(l)
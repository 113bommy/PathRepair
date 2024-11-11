from math import gcd
for _ in range(int(input())):
    a,b=map(int,input().split())
    print('finity' if gcd(a,b)==1 else 'infinity')
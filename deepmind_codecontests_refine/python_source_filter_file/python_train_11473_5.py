from math import gcd
for _ in range(int(input())):
    a,b=map(int,input().split())
    print('Finity' if gcd(a,b)==1 else 'Infinity')
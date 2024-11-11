import math as mp
a,b=map(int,input().split())
print(a*b//mp.gcd(a,b))
from math import gcd
n = int(input())
print(360*n//gcd(n,360)//n)
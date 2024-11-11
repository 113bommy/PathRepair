from fractions import *

def ppcm(a, b):
    return a * b // gcd(a, b);

n, a, b, p, q = [int(s) for s in input().split()]

if q < p:
    a, b, p, q = b, a, q, p

print(int(p * ((n//a) - (n//ppcm(a, b))) + q * (n//b)))

from math import gcd
a,b,c,d=list(map(int,input().split()))
print(min(a//(c//gcd(c,d)),b//(gcd(c,d))))
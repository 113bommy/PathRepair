import math
n,a,b,p,q=map(int, input().split())

total = p*(n//a) + q*(n//b) - min(p,q)*(n//(a*b/math.gcd(a,b)))
print(total)
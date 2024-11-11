import math
n=int(input())
print(int(n*360/math.gcd(n,360)/n))
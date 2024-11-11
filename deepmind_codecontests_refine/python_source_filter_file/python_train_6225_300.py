import math
a,b = list(map(int,input().split()))
print(abs(a*b)//math.gcd(a,b))
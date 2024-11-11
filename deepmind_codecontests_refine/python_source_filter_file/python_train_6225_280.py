import math
A,B=map(int,input().split())
c=A*B//math.gcd(A,B)
print(c)
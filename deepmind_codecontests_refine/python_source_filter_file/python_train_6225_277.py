import math
A,B=map(int,input().split())
x=A*B//math.gcd(A,B)

print(x)

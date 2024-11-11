import math
A,B=map(int,input().split())
c=A*B/math.gcd(A,B)
print(int(c))
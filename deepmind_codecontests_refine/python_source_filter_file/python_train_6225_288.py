import math
A,B = map(int,input().split())

g = math.gcd(A,B)
print(int(A*B//g))
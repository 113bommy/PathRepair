import math
A,B=map(int,input().split())
print(int(A*B/math.gcd(A,B)))
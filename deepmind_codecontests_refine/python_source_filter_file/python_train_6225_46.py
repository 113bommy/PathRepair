import math
A,B = list(map(int,input().split()))
print(int(A*B/math.gcd(A,B)))
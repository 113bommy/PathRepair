import math
A,B=map(int,input().split())
lcm=(A*B)//math.gcd(A,B)

print(lcm)
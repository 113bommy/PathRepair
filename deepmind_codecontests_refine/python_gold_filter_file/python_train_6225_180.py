A,B = map(int,input().split())
import math
g = math.gcd(A,B)
print(A//g*B)
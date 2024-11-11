A,B = map(int,input().split())
import math
d = math.gcd(A,B)
print(A*B//d)
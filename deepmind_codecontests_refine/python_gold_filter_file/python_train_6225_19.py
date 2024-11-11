A,B = map(int,input().split())

import math
G = math.gcd(A,B)

print(A*B//G)
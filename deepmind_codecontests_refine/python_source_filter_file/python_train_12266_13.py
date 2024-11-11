N,X=map(int,input().split())
*C,=map(int,input().split())

t=[c-X for c in C]

import math
from functools import reduce
print(reduce(math.gcd, t))
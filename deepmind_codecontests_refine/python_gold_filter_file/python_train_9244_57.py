import math
N=int(input())
L=[int(input()) for i in range(5)]
print(math.ceil(N/min(L)+4))
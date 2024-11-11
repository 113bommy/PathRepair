import math
N=int(input())
A=[int(input()) for i in range(5)]
print(math.ceil(N/min(A)+4))
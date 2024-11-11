import math

n=int(input())
a=[int(input()) for i in range(n)]

print(4+math.ceil(n/min(a)))
from math import sqrt, ceil, floor
n = int(input())
sq = floor(sqrt(n))
print(n, sq + ceil(n/sq))

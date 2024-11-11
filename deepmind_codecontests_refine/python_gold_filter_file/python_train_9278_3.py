from math import sqrt, ceil, floor
n = int(input())
sq = floor(sqrt(n))
print(sq + ceil(n/sq))

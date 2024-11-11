import math

s = int(input())
sq = math.ceil(math.sqrt(s))
l = map(str, [sq, 1, sq**2-s, sq, 0, 0])
print(" ".join(l))
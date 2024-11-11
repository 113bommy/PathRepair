import math
a, b = map(int, input().split())
print(a if a < b else b, math.floor(abs(a-b)/2))

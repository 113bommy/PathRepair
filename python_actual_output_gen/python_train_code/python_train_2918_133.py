import math
a, b = map(int, input().split())
print(a if a < b else b, math.floor((a-b)/2))

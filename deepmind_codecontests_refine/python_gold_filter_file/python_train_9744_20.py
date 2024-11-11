import math
n, k = map(int, input().split())

daf = list(map(int, input().split()))
jum = sum(daf)

has = (n * (k - 0.5) - jum) / 0.5
has = math.ceil(has)
print(max(0,has))

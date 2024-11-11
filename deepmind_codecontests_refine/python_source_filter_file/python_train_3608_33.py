import math
n = int(input())
l = [int(c) for c in input().split()]
s = math.ceil(sum(l) / 2)
i = -1
while i < n and s > 0:
    i += 1
    s -= l[i]
print(i)
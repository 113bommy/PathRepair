import math
n, R = map(int, input().split())
l = 0
r = 7
for t in range(100000):
    m = (l + r) / 2
    k = math.degrees(math.asin(m / (R + m))) * 2 * n
    if math.degrees(math.asin(m / (R + m))) * 2 * n <= 360:
        l = m
    else:
        r = m
print(l)
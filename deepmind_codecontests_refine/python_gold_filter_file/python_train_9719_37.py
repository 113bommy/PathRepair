import math
a, b, c = map(int, input().split())
volume_sqr = math.sqrt(a * b * c)
print(int(4 * (volume_sqr / a + volume_sqr / b + volume_sqr / c)))

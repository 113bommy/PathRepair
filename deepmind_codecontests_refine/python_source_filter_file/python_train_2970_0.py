import math
ln = input().split(" ")
n = int(ln[0])
r = int(ln[1])

tot_area = n / 2 * (math.sin(2 * math.pi / n)) * r * r

if n < 5 * 10 ** 7:
    x = (1 - math.cos(2 * math.pi / n)) / (1 - math.cos(3 * math.pi / n))
else:
    x = 4 / 9
x *= r ** 2

small_area = n / 2 * math.sin(3 * math.pi / n) * x

print(tot_area - small_area)

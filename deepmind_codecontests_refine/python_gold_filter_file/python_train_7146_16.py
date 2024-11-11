import math
R, x1, y1, x2, y2 = map(int, input().split())

d2 = (x2 - x1) ** 2 + (y2 - y1) ** 2

if d2 >= R ** 2:
	xap, yap, rap = x1, y1, R
elif d2 == 0:
	rap = 0.5 * R
	xap, yap = x1 + rap, y1
else:
	dist = math.sqrt(d2)
	rap = 0.5 * (dist + R)
	k = rap / dist
	xap, yap = x2 + k * (x1 - x2), y2 + k * (y1 - y2)

print(xap, yap, rap)

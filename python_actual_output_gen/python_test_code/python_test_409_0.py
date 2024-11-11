x, t, a, b, da, db = (int(q) for q in input().split())
if (x in (a - da * i + b - db * j for i in range(t) for j in range(t)) or
    (a > x and (a - x) % da == 0 and (a - x) // da < t) or
    (b > x and (b - x) % db == 0 and (b - x) // db < t) or
    x == 0):
	print('YES')
else:
	print('NO')

h, m, s, a, b = map(int, input().split())
x, y, z = sorted([h + m / 60 + s / 3600, m / 5 + s / 300, s / 5])
if a > b: a, b = b, a
d = (x < a) * (b < y) + (y < a) * (b < z) + (b > z) * (a < x) + (b < x) + (a > z)
print('YES' if d else 'NO')

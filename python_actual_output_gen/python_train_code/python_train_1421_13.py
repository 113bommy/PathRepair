a, b, c, d = map(int, input().split())
misha_points = max(3*a/10, a - (b/250 * d))
vasya_points = max(3*b/10, b - (b/250 * d))
if vasya_points == misha_points:
	print('Tie')
else:
	print('Vasya' if vasya_points > misha_points else 'Misha')
a, b, c, d = map(int,input().split())
m = a//250
n = b // 250
points_misha = max((3*a)/10,a-m*c)
points_vasya = max((3*b)/10,b-n*c)
if points_vasya > points_misha:
	print('Vasya')
elif points_misha > points_vasya:
	print('Misha')
else:
	print('Tie')
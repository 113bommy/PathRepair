a = list(map(int, input().split()))
a = sorted(a)

if a[1] + a[2] > a[3] or a[0] + a[1] > a[2]:
	print('TRAINGLE')
elif a[1] + a[2] == a[3] or a[0] + a[1] == a[2]:
	print('SEGMENT')
else:
	print('IMPOSSIBLE')
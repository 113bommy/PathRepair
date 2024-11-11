n, hh = [int(x) for x in input().split(' ')]

aa = [int(x) for x in input().split(' ')]

l, r = 0, len(aa)+1

while (r - l > 1):
	h = hh
	c = (l + r) // 2

	a = sorted(aa[:c])

	if len(a) % 2 == 1:
		a = [0] + a

	# print(a)
	ans = True
	i = 0
	for i in range(len(a) // 2):
		if h < a[2 * i + 1]:
			ans = False
		# print(f'loaded [{a[2 * i]}, {a[2 * i + 1]}]')
		h -= a[2 * i + 1]

	if ans == True:
		# print(f'fine with {c}')
		l = c
	else:
		# print(f'bad with {c}')
		r = c

print(l)
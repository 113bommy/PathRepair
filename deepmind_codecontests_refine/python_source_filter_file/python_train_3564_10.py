t = int(input())
for x in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	b = list(map(int,input().split()))
	v = [999999999999999]*3
	deff = 0
	v0 = 0
	v2 = 0
	v1 = 0
	for i in range(n):
		if a[i] == -1:
			if v0 == 0:
				v[0] = i
				v0 = 1
		elif a[i] == 0:
			if v1 == 0:
				v[1] = i
				v1 = 1
		elif a[i] == 1:
			if v2 == 0:
				v[2] = i
				v2 = 1
	for i in range(1,n+1):
		if a[-i] - b[-i] > 0:
			if v[0] < n - i:
				pass
			else:
				if deff == 0:
					print('NO2')
					deff = 1
		if a[-i] - b[-i] < 0:
			if v[2] < n - i:
				pass
			else:
				if deff == 0:
					print('NO1',i)
					deff = 1
	if deff == 0:
		print('YES')
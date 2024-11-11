n = int(input())
a = list(map(int, input().split()))

ok, ng = n, 0
while ok-ng > 1:
	x = (ok+ng)//2
	#d = defaultdict(int)
	d = dict()
	last = 0
	valid = True
	if x == 1:
		for i in range(n-1):
			if a[i] >= a[i+1]:
				valid = False
				break
		if valid:
			ok = x
		else:
			ng = x
		continue

	for i in range(n-1):
		dels = []
		if a[i] < a[i+1]:
			last = a[i+1]
			continue

		j = a[i+1]
		for k in d.keys():
			if last < j:
				dels.append(k)

		while j > 0:
			if j in d and d[j] == x-1:
				d[j] = 0
				dels.append(j)
				j -= 1
			else:
				break

		if j in d:
			d[j] += 1
		else:
			d[j] = 1

		for k in dels:
			del d[k]

		if 0 in d:
			valid = False
			break
		last = j

	if valid:
		ok = x
	else:
		ng = x
print(ok)
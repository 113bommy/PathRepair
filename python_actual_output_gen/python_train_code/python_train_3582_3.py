n = int(input())
for _ in range(n):
	m, k = map(int, input().split(" "))
	ks = [1]
	kk = 1
	while kk <= 10**6:
		kk *= k
		ks += [kk]
	ns = list(map(int, input().split(" ")))
	fail = False
	for x in ns:
		upper = len(ks) - 1
		while x > 0 and upper >= 0:
			if ks[upper] != None and ks[upper] <= x:
				x -= ks[upper]
				ks[upper] = None
			upper -= 1
		if x > 0:
			fail = True
			break
	if fail:
		print("NO")
	else:
		print("YES")

def s():
	input()
	l = [[]for _ in range(100)]
	a = list(map(int,input().split()))
	for i,v in enumerate(a):
		l[v].append(i)
	c = 1
	cc = 0
	fs = [0,0]
	for i in l:
		if len(i) == 0:
			continue
		if len(i) == 1:
			a[i[0]] = c+1
			fs[c]+=1
			c = 1 - c
			continue
		fs[c] += 1
		fs[c-1] += 1
		for e in i[:len(i)//2]:
			a[e] = 1 + cc
		for e in i[len(i)//2:]:
			a[e] = 2 - cc
		if len(i) % 2 == 1:
			cc = 1 - cc
	print(fs[0]*fs[1])
	print(*a)
s()
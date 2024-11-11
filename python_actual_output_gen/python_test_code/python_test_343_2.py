def s():
	input()
	a = list(map(int,input().split()))
	b = list(range(1,len(a)+1))
	l,r = 0,0
	for i,v in enumerate(a):
		if v != b[i]:
			l = i
			break
	for i,v in reversed(list(enumerate(a))):
		if v != b[i]:
			r = i
			break
	a[l:r+1] = reversed(a[l:r+1])
	if a == b:
		print(l+1,r+1)
	else:
		print(0,0)
s()
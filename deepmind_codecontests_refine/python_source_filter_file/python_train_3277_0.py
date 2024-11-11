def s():
	s = list(input())
	l = len(s)-1
	input()
	a = list(map(int,input().split(' ')))
	a.sort()
	a.append(l//2+1)
	f = False
	t = 0
	for i in a:
		if f:
			for k in range(t,i-1):
				s[k], s[l-k] = s[l-k], s[k]
		f = not f
		t = i-1
	print(*s,sep='')
s()
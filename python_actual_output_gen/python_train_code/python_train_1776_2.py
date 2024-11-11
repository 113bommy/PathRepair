t = int(input())
for i in range(t):
	n,x = map(int, input().split())
	a = list(map(int, input().split()))
	a = list(set(a))
	a = sorted(a)
	s = x
	h = 1
	d = a[0]-1
	if(d <= s):
		h = a[0]
		s -= d
	else:
		h = s 
	for i in range(len(a)-1):
		d = a[i+1] - a[i] -1
		if(d <= s):
			s -= d
			h = a[i+1]	
		else:
			h += s
			s = 0
			break
	if(s > 0):
		h += s
		
	print(h)
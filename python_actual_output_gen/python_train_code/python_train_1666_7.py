h=int (input())
for i in range(h):
	a,b=map(int,input().split())
	c=[int(i)for i in input().split()]
	d=sorted(c)[-1::-1]
	e=0
	f=0
	for j in d:
		e=e+j
		f+=1
		if e/f<b:
			t=f-1
			break
	if e/a>=b:
		print(a)
	else:
		print(h)
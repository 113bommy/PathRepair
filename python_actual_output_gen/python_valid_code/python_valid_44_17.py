a=int(input())

r1=r2=l1=l2=0
for i in range(a):
	l, r = map(int, input().split())
	if r%2==1:
		r1=int(r/2)+1
		r2=int(r/2)
	else:
		r1=r2=int(r/2)
		
	if l%2==1:
		l1=int(l/2)+1
		l2=int(l/2)
	else:
		l1=l2=int(l/2)
	
	a = (-r1**2) + r2*(r2+1)
	b = (-l1**2) + l2*(l2+1)
	
	print(a-b)
	
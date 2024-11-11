def I(): return(list(map(int,input().split())))
 
for __ in range(int(input())):
	n,d=I()
	a=I()
	s=a[0]
	l=1
	for i in range(1,n):
		l=i
		d-=(i)*a[i]
		if d<=0:
			break
		s+=a[i]
	if d<=0:
		# s-=a[l]
		d+=(l)*a[l]
		s+=d//(l)
	print(s)
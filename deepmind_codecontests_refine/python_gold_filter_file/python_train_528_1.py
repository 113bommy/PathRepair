q = input()
q = int(q)

for i in range(q):
	a = input()
	a = list(a.split(" "))
	for j in range(3):
		a[j]=int(a[j])
	d=0
	moves = 0
	if a[0]<a[1]:
		a[0],a[1]=a[1],a[0]
	d = a[1]
	a[0]-=a[1]
	k = a[2]
	d += (a[0]//2)*2
	moves =  d
	a[0] = a[0]%2
	k-=moves

	if a[0]>0 and k<=0:
		print(-1)
		continue
	if k<0:
		print(-1)
		continue

	if a[0]==0:
		if k%2==0:
			d+=k
		else:
			d += k-2
	else:
		d+=k-1
	print(d)
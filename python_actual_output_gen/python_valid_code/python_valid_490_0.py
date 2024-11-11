q=int(input())
for qwerty in range(q):
	kpz70=input()
	x,y=map(int,input().split())
	a=[0 for i in range(y)]
	b=0
	for i in range(x):
		z=list(map(int,input().split()))
		for j in range(y):
			if(z[j]>a[j]):
				a[j]=z[j]
		if(x>y):
			z.sort()
			if(z[y-2]>b):
				b=z[y-2]
	if(b>0):
		a.append(b)
	print(min(a))
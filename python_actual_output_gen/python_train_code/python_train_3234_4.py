T=int(input())
for i in range(T):
	x=list(map(int,input().split()))
	a,b,c,r=x[0],x[1],x[2],x[3]
	t=0
	up=c+r
	low=c-r
	if a>b:
		b,a=a,b
	if (c<=a and c<=b):
		t= max(b,up)-max(a,up)
	if(c>=a and c>=b):	
		t=min(b,low)-min(a,low)
	else:
		t=(max(b,up)-up)+(max(a,low)-a)
	print(t)
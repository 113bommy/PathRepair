m=10**9+7
f=max
r=range
for _ in r(int(input())):
	x,y=sorted(map(int,input().split()))
	s=-1
	i=j=1
	while j<=x and i+j<=y:i,j,s=j,i+j,s+1
	if x<2 or y<3:print(1,x*y%m);continue
	a=f(0,(y-j)//i+1)+f(0,(x-j)//i+1)
	i=j=1
	for c in r(s):
		k,l=j,i+j*2
		for _ in r(s-c):k,l=l,k+l
		if x>=k:a+=f(0,(y-l)//k+1)
		if y>=k:a+=f(0,(x-l)//k+1)
		i,j=j,i+j
	print(s+1,a%m)
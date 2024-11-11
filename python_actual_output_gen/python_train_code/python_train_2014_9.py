q=int(input())
m=10**9+7
for _ in range(q):
	x,y=sorted(map(int,input().split()))
	s=-1
	i=j=1
	while j<=x and i+j<=y:
		i,j=j,i+j
		s+=1
	if x==1 or y<3:print(1,x*y%m)
	else:
		a=max(0,(y-j)//i+1)+max(0,(x-j)//i+1)
		i=j=1
		for c in range(s):
			k,l=j,i+j*2
			for _ in range(s-c):k,l=l,k+l
			if x>=k:a+=max(0,(y-l)//k+1)
			if y>=k:a+=max(0,(x-l)//k+1)
			i,j=j,i+j
		print(s,a%m)
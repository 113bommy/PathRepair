m=10**9+7;f=lambda a:max(0,(a-l)//k+1);r=range
for _ in r(int(input())):
	x,y=sorted(map(int,input().split()));s=-1;i=j=k=l=1
	while l<=x and k+l<=y:k,l,s,a=l,k+l,s+1,f(y)+f(x)
	for c in r(s):
		k,l=j,i+j*2
		for _ in r(s-c):k,l=l,k+l
		a,i,j=a+(y>=k)*f(x)+(x>=k)*f(y),j,i+j
	if x<2 or y<3:print(1,x*y%m)
	else:print(s+1,a%m)
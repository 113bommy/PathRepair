n,m=map(int,input().split())
a=list(map(int,input().split()))
l,r=-1,m-1
while l+1<r:
	mid,p,f=(l+r)//2,0,1
	for i in a:
		if (m-i+p)%m>mid:
			if i<p:
				f=0
				break
			p=i
	if f:
		r=mid
	else:
		l=mid
print (r)
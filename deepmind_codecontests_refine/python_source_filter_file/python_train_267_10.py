c,v0,v1,a,l=map(int,input().split())
r=l
ans=0
v0-=a
while r<c:
	v0=min(v1,v0+a)
	r=min(r-l+v0,c)
	ans+=1
print (ans)

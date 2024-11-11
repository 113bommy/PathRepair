#56 ABC136E
n,k=map(int,input().split())
a=list(map(int,input().split()))
s=sum(a)

res=[]
for d in range(1,int(s**0.5)+1):
	if s%d==0:
		res.append(d)
		res.append(s//d)
ans=[]
for d in res:
	r1=[t%d for t in a]
	r1.sort()
	r2=[(d-t)%d for t in r1]
	r2=r2[::-1]
	x=[r1[0]]
	_=[x.append(x[-1]+r1[i]) for i in range(1,n)]
	y=[r2[0]]
	_=[y.append(y[-1]+r2[i]) for i in range(1,n)]
	#print(r1,r2,d,x,y)
	for i in range(n-1):
		#print(x[i],y[-i-2])
		if x[i]==y[-i-2] and x[i]<k:
			ans.append(d)
			break
print(max(ans))
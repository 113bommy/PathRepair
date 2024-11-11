n,m=map(int,input().split())
a=list(map(int,input().split()))
if n==1:
	print(0)
ans = 0
a.sort(reverse=True)
p=a[0]
for j in range(n-1):
	#k=a[j]-a[j+1]
	if p<=0:
		ans+=a[j]-1
		continue
	if a[j+1]>=p-1:
		ans+=a[j]-1
		p-=1
	else:
		k=p-a[j+1]
		ans+=a[j]-k
		p-=k
	
	#p=a[j+1]
	#print(ans,p)
if p<0:
	p=0
ans+=a[-1]-max(p,1)
print(ans)

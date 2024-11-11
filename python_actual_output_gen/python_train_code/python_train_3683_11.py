N=int(input())
k=[]
a=list(map(int,input().split()))
c=1
for i in range(N-1):
	if a[i]==a[i+1]:
		c+=1
	else:
		k.append(c)
		c=1
k.append(c)
ans=0
for i in range(len(k)-1):
	ans=max(ans,min(k[i],k[i+1]))
print(ans)
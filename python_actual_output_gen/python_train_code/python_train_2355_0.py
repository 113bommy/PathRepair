n,k=map(int,input().split())
l=list(map(int,input().split()))
l.sort()
presum=[0]*(n+1)
for i in range(n):
	presum[i+1]=presum[i]+l[i]
i,j=0,0
ans1,ans2,curr=1,l[0],0
print(l)
while(j<n):
#	print(i,j,(j-i+1)*(l[j])-(presum[j+1]-presum[i]),ans1,ans2)
	if (((j-i+1)*(l[j])-(presum[j+1]-presum[i]))<=k):
		if (j-i+1)>ans1:
			ans1=j-i+1
			ans2=l[j]
		j+=1
	else:
		i+=1
print(ans1,ans2)

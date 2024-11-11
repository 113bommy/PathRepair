n,p=map(int,input().split())
k=1
while(n-p*k >0):
	count=0

	temp=n-p*k
	while(temp>0):
		if temp&1:
			count+=1
		temp=temp>>1

	if count<=k:
		break
	k+=1
if n-p*k>0:
	print(k)
else:
	print(-1)
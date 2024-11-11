n,k=input().split()
k=int(k)
ans=0
zerocount=0
i=0
try:
	if len(n)>k:
		while(zerocount!=k):
			if n[-1*i]!='0':
				ans+=1
			else:
				zerocount+=1
			i+=1
	else:
		ans=len(n)-1
except:
	ans=len(n)-1
print(ans)
n,r=map(int,input().split())
h=list(map(int,input().split()))
ans=0
p=-1
for i in range(len(h)):
	if(h[i]==1):
		if(i-r>p):
			ans=0
			break
		temp=0
		for j in range(i,len(h)):
			if(h[j]==1):
				if(j-r<=p):
					temp=j+r-1
				else:
					break
		ans+=1
		p=temp
		if(p>=n-1):
			break
if(ans and p>=n):	
	print(ans)
else:
	print(-1)		


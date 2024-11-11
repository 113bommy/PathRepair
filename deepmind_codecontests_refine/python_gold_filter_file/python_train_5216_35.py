n= int(input())
l=list(map(int,input().split()))
if(n==1):
	print(1)
else:
	t=[]
	ans=1
	for i in range(n-1):
		if(l[i]*2>=l[i+1]):
			ans+=1
		else:
			t.append(ans)
			if(i==n-2):
				t.append(1)
			ans=1
		if(i==n-2 and l[i]*2>=l[i+1]):
			t.append(ans)

	print(max(t))

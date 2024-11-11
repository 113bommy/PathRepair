t=int(input())

for _  in range(t):
	n,d=map(int,input().split())
	arr= list(map(int,input().split()))
	ans=arr[0]
	for i in range(1,n):
		# print(ans,d,i)
		if(arr[i]*(i)<=d):
			ans+=arr[i]*i
			d-=arr[i]*i
		else:
			ans+=d//i
			break
	print(ans)

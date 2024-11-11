

n,k=map(int,input().split(" "))

low=0
high=n+2
ans=-1

while(low<=high):
	mid=(low+high)//2

	add=(mid*(mid+1))//2

	if(add-(n-mid)==k):
		ans=n-mid
		break
	elif(n-add>k):
		low=mid+1
	else:
		high=mid-1

print(ans)
	




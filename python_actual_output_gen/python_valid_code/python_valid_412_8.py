# your code goes here
n,a,b=map(int,input().split())
ans=-1
for i in range(1,5):
	temp=a//i+b//i
	if(min(a//i,b//i)==0):
		pass
	elif(temp>=n):
		ans=max(i,ans)
print(ans)
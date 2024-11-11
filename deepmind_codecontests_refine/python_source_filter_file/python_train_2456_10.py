n,k=map(int,input().split())
a=list(map(int,input().split()))
x=min(a)
flag=0
for i in range(len(a)):
	if((a[i]-x)%k!=0):
		flag=1
		break
if(flag==0):
	for i in range(len(a)):
		a[i]=(a[i]-x)/k
	print(sum(a))
elif(flag==1):
	print(-1)
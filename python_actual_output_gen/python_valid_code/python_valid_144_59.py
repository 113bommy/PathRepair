n,k=map(int,input().split())
lst=list(map(int,input().split()))
c=0
for i in range(1,len(lst)):
	if lst[i]-lst[i-1]>k:
		c=0
	else:
		c+=1
print(c)
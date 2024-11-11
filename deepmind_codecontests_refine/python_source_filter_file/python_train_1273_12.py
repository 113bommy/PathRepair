n=int(input())
l1=list(map(int,input().split()))
l2=list(map(int,input().split()))
l3=[]
for i in range(n):
	l3.append(l1[i]-l2[i])
l3.sort()
count=0
print(l3)
for i in range(n-1):
	store=(-l3[i])
	k=i+1
	j=n
	index=i

	while(k<j):
		mid=(k+j)//2
		if(l3[mid]<=store):
			
			index=mid
			k=mid+1
		else:
	
			j=mid
	#print(index)
	count+=n-(index+1)
print(count)


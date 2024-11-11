t = int(input())
for j in range(t):
	n,m=map(int,input().split())
	arr=list(map(int,input().split()))
	arr.sort()
	if n>m:
	    print('-1')
	    continue
	total=sum(arr)
	total*=2
	total*=int(m/n)
	for i in range(0,m%n):
	    total+=arr[i]+arr[i+1]
	print(total)
	node=1
	for i in range(m):
	    temp=node+1
	    if(temp>n):
	        temp=1
	    print(node,temp)
	    node=temp
	    

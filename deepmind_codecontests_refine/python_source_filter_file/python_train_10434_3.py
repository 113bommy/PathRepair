# your code goes here
for _ in range(int(input())):
	n,k=map(int, input().split())
	a=list(map(int, input().split()))
	a.sort()
	s=set()
	f=0
	for i in range(n):
		j=30
		while a[i]>0:
			while j>=0 and a[i]<k**j:
				j-=1
			
			if a[i]>=k**j:
			    if j in s:
    				f=1
    				break
			    a[i]-=k**j
			    s.add(j)
		if f==1:
			break
	if f==0:
		print("YES")
	else:
		print("NO")
		
		
			
			
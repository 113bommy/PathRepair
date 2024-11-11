n,k=map(int,input().split())
ans=0
lst1=[]
for i in range(0,k+1):
	lst1.append(i)

while(n>0):
	n=n-1
	t=int(input())
	lst=[]
	f=1
	c=0
	while(t>0):
		s=t%10
		lst.append(s)
		t=t//10
	for i in lst1:
		if(i in lst):
			c=c+1
		else:
			break

	if(c==len(lst1)):
		ans=ans+1
print(ans)
	


    
			
		


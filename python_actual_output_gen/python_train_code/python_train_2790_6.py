n,k=map(int,input().split())
l=list(map(int,input().split()))
l.sort()
mini=0
p=0
for i in range(n):
	if(l[i]-mini!=0):
		print(l[i]-mini)
		mini=l[i]
		l[i]=0
		p+=1
	if(i==k):
		break;
if(k-p>0):
	for i in range(k-p):
		print("0")
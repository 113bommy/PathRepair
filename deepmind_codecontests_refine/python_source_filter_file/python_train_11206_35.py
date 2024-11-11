import math as m
n,k=map(int,input().split())
d1={}
flag=0
l1=[k,m.sqrt(10**18)]
c=int(min(l1))
for i in range(1,c,1):
	a=n%i
	if a in d1.keys():
		flag=1
		break
	else:
		d1.update({a:i})	
if flag==0:
	print("Yes")
else:
	print("No")
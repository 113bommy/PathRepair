import math
l,r=map(int,input().split())
flag=0
for j in range((r-l)+1):
	a=l+j
	b=a+j+1
	for i in range(1,(r-l)):
		if((math.gcd(a,b)==1) and (math.gcd(b,b+i)==1 and math.gcd(a,b+i)!=1) and (b+i<=r)):
			c=b+i
			print(a,b,c)
			flag=1
			break
	if(flag==1):
		break
else:
	print(-1)
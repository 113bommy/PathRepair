import math
n,m=map(int,input().split())
l=list(map(int,input().split()))
q=list(map(int,input().split()))
if m>n:
	print("0/1")
elif n>m:
	if (l[0]>0 and q[0]>0) or (l[0]<0 and q[0]<0):
		print("Infinity")
	else:
		print("-Infinity")
    

else: 
	a=abs(l[0])
	b=abs(q[0])
	while math.gcd(a,b) >1:
		c=math.gcd(a,b)
		a=a//c
		b=b//c
	if l[0]>0 and q[0]>0:
		print(str(a)+"/"+str(b)) 
	elif l[0]<0 and q[0]<0:
		print(str(a)+"/"+str(b)) 
	else:
		print("-"+str(a)+"/"+str(b)) 
		
   
		

	
	
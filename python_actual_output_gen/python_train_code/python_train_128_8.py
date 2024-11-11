a=int(input())
b=int(input())
c=0
i=1
while a!=b:
	if a<b:
		a+=1
		c+=i
		if a<b:
			b-=1
			c+=i
	else:
		b+=1
		c+=i
		if a>b:
			a-=1
			c+=i		
	i+=1	
	break	
print(c)
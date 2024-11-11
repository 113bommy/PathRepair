n=int(input())
s=(input())
i=0
while(i<n):
	c=0
	f=0
	while(i<n and s[i]!='0'):
		c+=1
		f=1
		i+=1
	if(f==1):
		print(c,end="")
	c=0
	while(i<n and s[i]=='0'):
		c+=1
		i+=1
	if(c>=1):
		print((c-1)*'0',end="")
		if(i>=n):
			print('0')

	
	

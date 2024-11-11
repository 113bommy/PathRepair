l=input().split()
n=int(l[0])
b=int(l[1])
p=int(l[2])
c=0
m=input().split()
for i in range(len(m)):
	if(m[i]=='1'):
		if(b==0):
			c+=1
		else:
			b-=1
	if(m[i]=='2'):
		if(p==0 and b==0):
			c+=1
		elif(p==0):
			b-=1
		else:
			p-=1
print(c)

	
	
	
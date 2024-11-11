n,*abc=map(int,input().split())
ip=[0]*n
for i in range(n):
	tmp=input()
	if tmp=="AB":
		ip[i]=[0,1]
	elif tmp=="BC":
		ip[i]=[1,2]
	else:
		ip[i]=[0,2]
ans="Yes"
res=[0]*n
s=sum(abc)
if s==0:
	ans="No"
elif s==1:
	for i in range(n):
		i1=ip[i][0]
		i2=ip[i][1]
		ABC=[abc[i1],abc[i2]]
		if ABC==(0,0):
			ans="No"
		elif ABC==[0,1]:
			abc[i1]+=1
			abc[i2]-=1
			res[i]=i1
		else:
			abc[i1]-=1
			abc[i2]+=1
			res[i]=i2
else:
	i1=ip[0][0]
	i2=ip[0][1]
	if abc[i1]+abc[i2]==0:
		ans="No"
	else:
		for i in range(n):
			i1=ip[i][0]
			i2=ip[i][1]
			if abc[i1]*abc[i2]==0:
				if abc[i1]==0:
					abc[i1]+=1
					abc[i2]-=1
					res[i]=i1
				else:
					abc[i1]-=1
					abc[i2]+=1
					res[i]=i2
			elif i+1<n and ip[i+1]!=ip[i]:
				c=list(set(ip[i])&set(ip[i+1]))[0]
				if i1==c:
					abc[i1]+=1
					abc[i2]-=1
					res[i]=i1
				else:
					abc[i1]-=1
					abc[i2]+=1
					res[i]=i2
			else:
				abc[i1]+=1
				abc[i2]-=1
				res[i]=i1
print(ans)
dic={0:"A",1:"B",2:"C"}
if ans=="Yes":
	for i in range(n):
		print(dic[res[i]])
		'''
		if res[i]==0:
			print("A")
		elif res[i]==1:
			print("B")
		else:
			print("C")
		'''
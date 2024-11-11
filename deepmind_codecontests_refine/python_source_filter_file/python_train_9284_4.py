def removeX(s,p):
	if (p==len(s)):
		return s
	while s[p]!='X':
		p+=1
		if (p==len(s)):
			return s
	j=0
	while s[p+j]=='X':
		j+=1
		if (p+j==len(s)):
			break
	return removeX(s[0:p+1]+s[p+j:],p+1)

def doable(lenght,a,b,parity):
	for x in range((lenght-a)//2+2): 
		y=lenght-a-x
		#print(x,y)
		if ((not((x>=b) & (x<a)))&(not(x>=2*b))&(not((y>=b) & (y<a)))&(not(y>=2*b))):
			e=0
			#print('oui')
			if((x>=a)&(x<2*b)):
				e+=1
			if((y>=a)&(y<2*b)):
				e+=1
			if((parity+e)%2==0):
				return 1
	return 0

for i in range(int(input())):
	a,b=[int(x) for x in input().split()]
	v=[0,0,0]
	s=removeX(input(),0)
	for y in s.split('X'):
		k=len(y)
		if ((k>=b) & (k<a)):
			v[0]+=1
		elif ((k>=a) & (k<2*b)):
			v[1]+=1
		elif (k>=2*b):
			v[2]+=1
			lenght=k
	#print(v)
	if ((v[0]>0) | (v[2]>1)):
		print('NO')
	elif (v[2]==1):
		if (lenght-a>=4*b):
			print('NO')
		else:
			if (doable(lenght,a,b,v[1]%2)==1):
				print('YES')
			else:
				print('NO')
	else:
		if (v[0]%2==0):
			print('NO')
		else:
			print('YES')


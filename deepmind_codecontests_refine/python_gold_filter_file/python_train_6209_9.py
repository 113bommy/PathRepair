"""s=input().lower().split(" ")
#print(s)
t=s[0][0]+s[1][0]
res=s[0][0]
i=1
while i<len(s[0]):
	res=res+s[0][i]
	if ((i+1)!= len(s[0])):
		temp=s[0][i+1]
	else:
		break	
	if(i>len(s[0]) or s[0][i]<temp or s[0][i]):
		break
	i=i+1
	#print(res)
res=res+s[1][0]
if(res[1]<t[1]):
	print(res)
else:
	print(t)"""
s=input().lower().split(" ")
x=s[0][0]+s[1][0]
i=1
while i<len(s[0]):
	t=x[:-1]+s[0][i]+x[-1]
	"""print("before")
	print('t=',t)
	print('x=',x)"""
	if(t<x):
		x=t
	else:
		break	
	i=i+1
	"""print("after")
	print('t=',t)
	print('x=',x)"""
	#print(i)
print(x)							
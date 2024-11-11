l=[]
c=0
s=input().split()
for i in s:
	if i=="+":
		l[c-2]=l[c-2]+l[c-1]
		c=c-1
	elif i=="-":
		l[c-2]=l[c-2]-l[c-1]
		c=c-1
	elif i=="*":
		l[c-2]=l[c-2]*l[c-1]
		c=c-1
	else:
		l[c]=int(i)
		c=c+1
printl[0]

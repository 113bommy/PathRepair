s=input()
n0=0
n1=0
for  i in s:
	if i=='0':
		n0+=1
	else:
		n1+=1
if n0==0:
	tt=0
	for i in range(len(s)):
		if tt%2==0:
			print(1,1)
		else:
			print(1,3)
		tt+=1
	exit()
if n1==0:
	tt=0
	for i in range(len(s)):
		if tt%2==0:
			print(1,1)
		else:
			print(3,1)
		tt+=1
	exit()
xx=0
yy=0
for i in range(len(s)):
	if s[i]=='0':
		if xx%4==0:
			print(1,1)
		elif xx%4==1:
			print(2,1)
		elif xx%4==2:
			print(3,1)
		else:
			print(4,1)
		xx+=1
	else:
		if yy%4==0:
			print(3,1)
		if yy%4==1:
			print(3,3)
		if yy%4==2:
			print(4,1)
		if yy%4==3:
			print(4,3)
		yy+=1
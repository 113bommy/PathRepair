for _ in range(int(input())):
	n=int(input())
	string=[]
	for i in range(n):
		l=input()
		string.append(l)
	c=0
	p,q=len(string)-2,len(string[0])-1
	r,s=len(string)-1,len(string[0])-2
	x=string[0][1]+string[1][0]
	y=string[p][q]+string[r][s]
	tempx=x
	tempy=y
	if x[0]==x[1]:
		if x[0]=='0':
			y='11'
		else:
			y='00'
	elif y[0]==y[1]:
		if y[0]=='0':
			x='11'
		else:
			x='00'
	else:
		x='00'
		y='00'
	output=[]
	if x[0]!=string[0][1]:
		output.append((0,1))
	if x[1]!=string[1][0]:
		output.append((1,0))
	if y[0]!=string[p][q]:
		output.append((p,q))
	if y[1]!=string[r][s]:
		output.append((r,s))

	print(len(output))
	for x,y in output:
		print(x+1,y+1)
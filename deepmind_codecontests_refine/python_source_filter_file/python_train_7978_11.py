n=int(input())
c=input()
flag_u=0
flag_d=0


x,y=0,0
tot=0
if c[0]=='U':
	flag_u=1
	y+=1
else:
	flag_d=1
	x+=1

for i in range(len(c)-1):
	if c[i]=='U':
		y+=1
	else:
		x+=1
	
	if x==y:
		if c[i+1]=='R':
			if flag_u==1:
				flag_d=1
				flag_u=0
				tot+=1
			else:
				continue
		else:
			if flag_u==1:
				continue
			else:
				flag_u=1
				flag_d=0
				tot+=1
print(tot)


	
	

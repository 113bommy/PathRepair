s=list(map(int,list(input())))
n=len(s)
v=0
h=0
for i in range(n):
	if(s[i]==1):
		if(v==0):
			print(1,1)
			v=1
		else:
			print(3,1)
			v=0
	if(s[i]==0):
		print(h%4+1,3)
		h+=1

		

l=[]
s=12
for i in range(int(input())):
	y=input()
	for x in l:
		c=0
		for j in range(6):
			c+=x[j]!=y[j]
		s=min((c-1),s)
	l+=[y]
print(s//2)
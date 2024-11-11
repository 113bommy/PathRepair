n=int(input(""))
t=str(input(""))
c=t
for i in range(n,0,-1):
	if n%i==0:
		c = (c[0:i])[::-1]+c[i:n]

	else:
		continue
print(c)
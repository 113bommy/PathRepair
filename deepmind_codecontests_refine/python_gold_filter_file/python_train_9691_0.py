m,n=map(int,input().split())
s=[int(v) for v in input().split()]
c=2
for i in range(len(s)-1):
	val=(abs(s[i]-s[i+1])/(n*2))
	if val==1:
		c+=1
	elif val>1:
		c+=2
	else:
		c+=0
print(c)
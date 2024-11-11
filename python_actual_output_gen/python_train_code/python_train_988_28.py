a,b=map(int,input().split())
b=list(map(int,input().split()))
c=1
d=0
e=0
for i in range(a-1):
	if b[i]!=b[i+1]:
		c+=1
	else:
		e=max(d,c)
		d=c
		c=1
e=max(d,c)
print(e)

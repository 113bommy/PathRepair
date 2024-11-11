n,x=map(int,input().split())
c=0
for i in range(n):
	p=list(input().split())
	if p[0]=="+":
		x+=int(p[1])
	else:
		if int(p[1])<x:
			x-=int(p[1])
		else:
			c+=1
print(x,c,end=" ")

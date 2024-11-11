d,b,p=list(map(int,input().split()))
a=list(map(int,input().split()))
c=0
for i in range(d):
	if a[i]==1:
		if b==0:
			c+=1
		else:
			b-=1
	else:
		if b==0 and p==0:
			c+=1
		else:
			if p>=b:
				p-=1
			else:
				b-=1
print(c)
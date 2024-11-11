n,x,y=map(int,input().split())
a=list(map(int,input().split()))
c=0
for i in range(n//2):
	if a[i]!=a[n-1-i]:
		if a[i]==2 and a[n-1-i]!=2:
			if a[n-1-i]==0:
				c+=x
			else:
				c+=y
		elif a[n-i-1]==2 and a[i]!=2:
			if a[i]==0:
				c+=x
			else:
				c+=y
		else:
			print(-1)
			exit()
	elif a[i]==a[n-1-i]==2:
		c+=2*min(x,y)
if n%2!=0 and a[n//2]==2:
	c+=min(x,y)
print(c)
n=int(input())
a=list(map(int,input().split()))
c,d,z=0,0,0
for i in range(n):
	if a[i]<-1:
		c+=-(a[i]+1)
		d+=1
	elif a[i]>1:
		c+=a[i]-1
	elif a[i]==-1:
		d+=1
	elif a[i]==0:
		z+=1
if d%2==0:
	print(c+z)
else:
	if z>=d%2:
		print(c+2*d%2)
	else:
		print(c+2*(d%2-z)+z)
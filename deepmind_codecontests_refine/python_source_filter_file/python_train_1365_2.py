n,p=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
x=a[p-1]+b[0]
z = p-2
c=0
for i in range(1,n):
	if b[i]+a[z]<=x:
		c+=1
		z-=1
	if z<0:
		break
print(p-c)			


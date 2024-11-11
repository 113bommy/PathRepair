n=int(input())
a=[0]*n
b=[0]*n
c=0
for i in range(n):
	a[i],b[i]=map(int,input().split())
	if b[i]-a[i]>0:
		c+=1
print(c)
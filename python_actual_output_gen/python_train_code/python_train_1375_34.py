n=int(input())
a=[]
c=0
for i in range(n):
	a.append(input())
for i in range(1,n):
	if(a[i-1]==a[i]):
		c+=1
print(c)
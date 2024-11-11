n=int(input())
a=list(map(int,input().split()))
c=0
d=[0]
for i in range(n):
	if a[i]-a[i-1]>=0:
		c+=1
	else:
		d.append(c)
		c=1
print(max(max(d),c))
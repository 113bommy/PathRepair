n=int(input())
l=list(map(int,input().split()))
x=l[0]
i,f=0,0
for j in range(1,n):
	if f==0:
		if x>l[j]:
			y=l[j]
			f=1
	if x<l[j]:
		y=x
		x=l[j]
		i=j+1
	elif f==1:
		if y<l[j]:
			y=l[j]
print(i,y)
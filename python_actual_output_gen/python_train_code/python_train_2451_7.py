n,a,x,b,y=map(int,input().split())
if x<a:
	i=n-(x-a+1)
else:
	i=x-a+1
if b<y:
	j=n+(b-y+1)
else:
	j=(b-y)+1
p=min(i,j)
k=0
while k<p:
	if a==b:
		print("YES")
		exit()
	else:
		if a==n:
			a=1
		else:
			a+=1
		if b==1:
			b=n
		else:
			b-=1
	k+=1

print("NO")	




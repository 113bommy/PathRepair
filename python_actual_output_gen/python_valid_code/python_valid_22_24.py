n=int(input())
p=list(map(int,input().split()))
c=0
bic=0
back=0
if n==1:
	c+=p[0]
elif n==2:
	c+=p[0]
	bic+=p[1]
else:
	for i in range(0,n-2,3):
		c+=p[i]
		if i+1<n:
			bic+=p[i+1]
		if i+2<n:
			back+=p[i+2]
d={c:"chest",bic:"biceps",back:"back"}
print(d[max(c,bic,back)])

def func(a,b,c,r):
	a,b=min(a,b),max(a,b)
	if c<a:
		sum=0
		if c+r>a:
			sum=sum+c+r-a
			sum=min(sum,b-a)
	elif c>a and c<b:
		sum=min(r,c-a)
		sum=sum+min(r,b-c)
	else:
		sum=0
		if c-r<b:
			sum=sum+b-(c-r)
			sum=min(sum,b-a)
	return b-a-sum

t=int(input())
for _ in range(t):
	l=list(map(int,input().split()))
	a,b,c,r=l[0],l[1],l[2],l[3]
	print(func(a,b,c,r))
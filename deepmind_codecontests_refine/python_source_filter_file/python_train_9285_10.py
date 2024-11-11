n=int(input())
l=list(map(int,input().split()))
l.sort()
if n==1:
	print (l[0])
else:
	h=0
	v=0
	i=0
	j=n-1
	flag=False
	while i<=j:
		if flag:
			h+=l[i]
			i+=1
			flag=False
		else:
			v+=l[j]
			j-=1
			flag=True
	print (h**2+v**2)
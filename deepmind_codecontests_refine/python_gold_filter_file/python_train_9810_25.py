t=int(input())

while t>0:
	n=int(input())
	s=input()

	a=[]
	for i in range(n):
		if i==n-1:
			a.append([s[::-1],i+1])
			continue
		if (n-i)%2==0:
			l=s[i:n]+s[0:i]
		else:
			if i==0:
				l=s
			else:
				l=s[i:n]+s[i-1::-1]
			#print(i,l)
		a.append([l,i+1])

	a.sort(key=lambda x:x[0])
	k=a[0][1]
	for i in range(1,n):
		if a[i][0]==a[i][1]:
			if k>a[i][1]:
				k=a[i][1]
		else:
			break


	print(a[0][0])
	print(k)


	t-=1
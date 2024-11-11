from sys import exit
n,k = map(int,input().split())

if n<=2:
	print(*[i for i in range(1,n+1)])
	exit()
else:
	d = [1]
	for i in range(n+1):
		if k<=0:
			break
		if i%2==0:
			d.append(k+d[-1])
			k-=1
		else:
			d.append(d[-1]-k)
			k-=1
	if len(d)==n:
		print(*d)
	else:
		r = set(d)
		print(*d,*[i for i in range(1,n+1) if i not in r])


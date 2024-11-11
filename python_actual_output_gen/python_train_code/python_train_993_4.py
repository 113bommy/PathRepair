for x1 in range(int(input())):
	n=int(input())
	m=list(map(int,input().strip().split()[:n]))
	k=min(m)
	even=0
	odd=0
	for x in range(n):
		m[x]=m[x]-k
		if m[x]%2==0:
			even+=1
		else:
			odd+=1
	if even==odd or odd%2==0:
		print('YES')
	else:
		print('NO')
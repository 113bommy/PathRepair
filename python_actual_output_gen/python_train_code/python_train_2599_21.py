n=int(input())
l=[]
for i in range(n):
	l1=list(map(int,input().split()))
	l.append(l1[0])
	l.append(l1[n-1-i])
	l.append(l1[(n//2)])
	if i==(n//2):
		for i in range(n):
			l.append(l1[i])
			c=l1[n//2]
print(sum(l)-4*c)
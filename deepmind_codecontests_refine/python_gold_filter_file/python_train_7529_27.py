n=int(input())
if(n>1):
	l=[]
	c=0
	for i in range(n):
		l.append(list(map(int,input().split())))
	for i in range(n):
		c+=l[i][i]+l[n-1-i][i]+l[(n-1)//2][i]+l[i][(n-1)//2]
	print(c-3*(l[(n-1)//2][(n-1)//2]))
else:
	print(input())
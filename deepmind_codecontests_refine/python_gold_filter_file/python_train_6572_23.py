n=int(input())
l=[input() for i in range(n)]
c=0
for i in range(1,n-1):
	for j in range(1,n-1):
		if l[i][j]==l[i-1][j+1]==l[i+1][j-1]==l[i-1][j-1]==l[i+1][j+1]=='X':
			c+=1
print(c)
n,m=map(int,input().split())
l=[]
for i in range(n):
	l.append(list(input()))
c=0
for i in range(n):
	for j in range(m):
		if l[i][j]=='P':
			if i>0:
				if l[i-1][j]=='W':
					c+=1
					continue
			if i<n-1:
				if l[i+1][j]=='W':
					c+=1
					continue
			if j>0:
				if l[i][j-1]=='W':
					c+=1
					continue
			if j<n-1:
				if l[i][j+1]=='W':
					c+=1
					continue
print(c)
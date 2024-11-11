#https://codeforces.com/contest/462/problem/A
n=int(input())
l=[]
for i in range(n):
	l.append(input())
f=0
for i in range(n):
	for j in range(n):
		c=0
		if i-1>=0 and l[i-1][j]=='o':
			c+=1
		if i+1<n and l[i+1][j]=='0':
			c+=1
		if j-1>=0 and l[i][j-1]=='o':
			c+=1
		if j+1<n and l[i][j+1]=='0':
			c+=1
		if c&1:
			f=1
			break
	if f:
		break
if f:
	print('NO')
else:
	print('YES')

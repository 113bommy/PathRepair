n=int(input())
a=[]
for i in range(n):
	a.append(input())
for i in range(n):
	flag=0
	for j in range(i):
		if a[j]==a[i]:
			flag=1
	if flag==1:
		print('YES')
	else:
		print('NO')
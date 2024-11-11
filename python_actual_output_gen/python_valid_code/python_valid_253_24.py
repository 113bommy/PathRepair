a=int(input())
k=[None]*a
add=0
check=0
for i in range(0,a):
	k[i]=input()
	if k[i].count('OO')>0 and check==0:
		k[i]=k[i].replace("OO","++")
		check=check+1
	else:
		add=add+1
if add==a:
	print('NO')
else:
	print('YES')
for i in range(0,a):
	print(k[i])

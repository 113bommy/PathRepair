n=int(input())
flag=0
for i in range(n):
	a,b,c=input().split()
	b=int(b)
	c=int(c)
	if b>=2400 and c>2400:
		flag=1
		print('YES')
		break
if flag==0:
	print('NO')
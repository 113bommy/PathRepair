n,m=map(int,input().split())
s=input()
t=input()
if n==1:
	if s==t or s=='*':
		print('YES')
	else:
		print('NO')
elif s.count('*')==0:
	if n==m:
		print('YES')
	else:
		print('NO')
elif n>m+1:
	print('NO')
else:
	l=s.split('*')
	x=t[:len(l[0])]
	y=t[-len(l[1]):]
	if (l[0]==x and l[1]==y) or (s[:1]=='*' and l[1]==y) or (l[0]==x and s[-1:]=='*'):
		print('YES')
	else:
		print('NO')
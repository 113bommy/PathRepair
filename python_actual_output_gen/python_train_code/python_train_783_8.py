n,k=map(int,input().split())
s=input()
x=0
d=0
y=0
for i in range(len(s)):
	if s[i]=='G':
		x=i
for i in range(len(s)):
	if s[i]=='T':
		y=i		
if x>y:
	s=s[::-1]
	for i in range(len(s)):
		if s[i]=='G':
			x=i
	for i in range(len(s)):
		if s[i]=='T':
			y=i	
for i in range(x,len(s),k):
	if s[i]=='T':
		print('YES')
		d=1
		break
	elif s[i]=='#':
		print('NO')
		d=0
		break
if d!=1:
	print('NO')

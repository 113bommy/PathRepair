# import sys
# sys.stdin = open("test.in","r")
# sys.stdout = open("test.out.py","w")
n=int(input())
a=input()
for i in range(n):
	if a[i]=='4' or a[i]=='7':
		continue
	else:	
		print('NO')
		exit()
if a[-1]=='7' or a[-1]=='4':
	b,c=0,0
	for i in range(n//2):
		b+=int(a[i])
	for i in range(n//2,n):
		c+=int(a[i])
	if b==c:
		print('YES')
	else:
		print('NO')
else:
	print('NO')					
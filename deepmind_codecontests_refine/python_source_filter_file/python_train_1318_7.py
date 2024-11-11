s=list(input())
x=s.count('-')
y=s.count('o')
if(y==0 and x%2!=0):
	print('YES')
elif(y==0):
	print('NO')
elif(x%y==0):
	print('YES')
else:
	print('NO')
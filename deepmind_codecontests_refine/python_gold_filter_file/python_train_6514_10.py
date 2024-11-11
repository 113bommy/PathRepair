a,b = map(int,input().split())
if a+b == 0:
	print('NO')
	exit()
print('YES' if abs(a-b)<2 else 'NO')

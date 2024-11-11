#author YASH PATEL
 
a = int(input())
 
for i in range(a):
	x, y = map(int, input().split())
	if(x - y > 1):
		print('YES')
	else:
		print('NO')
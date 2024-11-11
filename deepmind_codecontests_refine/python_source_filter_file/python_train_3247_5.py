# your code goes here
for _ in range(int(input())):
	n = int(input())
	s1 = str(input())
	s2 = str(input())
	d = [s1,s2]
	row = 0
	for i in range(n):
		if(int(d[row][i]) > 2):
			row ^= 1
			if(int(d[row][i]) <= 2):
				x = 0
				break
	if(row == 0):
		print('NO')
	else:
		print('YES')
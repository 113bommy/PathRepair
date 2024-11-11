n = int(input())

l = []
f = 0
for i in range(n):
	temp = input()
	s = set(temp)
	if len(s) != 2:
		f = 1
		# break
	l.append(temp)
if f == 1:
	print('NO')
	

else:
	flag = 1
	count = 0
	for i in range(0,n//2+1):
		# print(l[i][])
		if l[i][i] == l[i][n-i-1]:
			count += 2
			# print('y')
			continue
		else:
			flag = 0
			break
	
	if flag == 0:
		print('hit')
		print('NO')
	else:
		flag = 1
		for i in range(n-1,n//2,-1):
			if l[i] == l[n-i-1]:
				count += 2
				continue
			else:
				flag = 0
				# print('nn')
				break
		count -= 1
		ac = 0
		for i in range(n):
			for j in range(n):
				if l[i][j] == l[0][0]:
					ac += 1
		if ac != count:
			flag = 0
		if flag == 0:
			# print('s')
			print('NO')
		else:
			print('YES')
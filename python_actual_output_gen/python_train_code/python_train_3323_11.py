n,k = [int(i) for i in input().split()]
if k > n*n/2:
	print('NO')
	exit()
print('YES')
for i in range(n):
	for j in range(n):
		if (i+j)%2==0 and k > 0:
			print('L',end='')
			k -= 1
		else:
			print('S',end='')
	print('')

n = int(input())
a = [int(i) for i in input().split()]
cnt = 0
curcnt = 0
cur = a[0]
for i in range(n):
	if a[i]==cur:
		curcnt+=1
	else:
		break

cnt = curcnt*1
if cnt==n: 
	print('YES')
else:

	curcnt = 0
	cur = a[i]
	br = 0
	for i in range(i, n):
		if a[i]==cur:
			curcnt+=1
			# print('+', end=' ')
		else:
			
			cur = a[i]
			if curcnt!=cnt:
				print(cur, curcnt, cnt, '!')
				br = 1
				break
			curcnt = 1
	if curcnt!=cnt:
		br = 1


	if br:
		print('NO')
	else:
		print('YES')



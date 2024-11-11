n = int(input())
v = list(map(int, input().split()))
if n == 1:
	print('NO') if v[0] == 0 else print('YES')
else:
	count = 0
	for i in v:
		if i == 0:
			count += 1
		if count > 1:
			break
	print('NO') if count > 1 else print('YES')
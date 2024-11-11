num = int(input())
array = [int(n) for n in map(int, input().split())]
valid = input()
maximum = -1
for i in range(num - 1):
	maximum = max(array[i], maximum)
	if i + 1 < maximum and valid[i] == '0':
		print('NO')
		break
else:
	print('YES')

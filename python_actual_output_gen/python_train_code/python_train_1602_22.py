a = bin(int(input()))
i = len(a) - 1
y = 1
res = 0
while a[i] != 'b':
	if a[i] == '1':
		if y == 1:
			res += 16
		if y == 2:
			res += 2
		if y == 3:
			res += 8
		if y == 4:
			res += 1
		if y == 5:
			res += 4
		if y == 6:
			res += 32
	i -= 1
	y += 1
print(res)
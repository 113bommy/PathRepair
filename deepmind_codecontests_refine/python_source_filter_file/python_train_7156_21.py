
st = list(input())
for i in range(len(st) - 3):
	set_ = set(st[i : i + 3])
	if len(set_) == 3 and '.' not in set_:
		print('YES')
		exit()


print('NO')
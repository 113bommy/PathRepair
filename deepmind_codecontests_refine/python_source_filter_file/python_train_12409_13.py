stdin = input().split()
begin = int(stdin[0])
ending = int(stdin[1])
value = -1
for i in range(begin + 1, ending):
	string = str(i)
	inter = True
	for k in string:
		if string.count(k) > 1:
			inter = False
			break
	if inter:
		value = i
print(value)
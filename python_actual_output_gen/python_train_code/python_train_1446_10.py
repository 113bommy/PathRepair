t = int(input())
for i in range(t):
	n = int(input())
	inp_str = input()
	flag = False
	for j in range(n):
		if inp_str[j] == "1":
			flag = True
			start = j
			break

	if flag == True:
		for j in range(n-1, -1, -1):
			if inp_str[j] == "1":
				end = j
				break

		value = max(n-start, n-end)
		print(2*value)

	else:
		print(n)
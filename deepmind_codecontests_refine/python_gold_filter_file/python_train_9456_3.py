abcd = input()

for i in range(1<<3):
	formula = abcd[0]
	for j in range(3):
		formula += "+-"[(i>>j)%2]
		formula += abcd[j+1]
	if eval(formula) == 7:
		print(formula + "=7")
		exit()
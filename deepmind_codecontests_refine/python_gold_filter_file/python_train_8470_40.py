import sys

n = int(input())

for year in range(n+1, 90000000):
	flag = True
	numbers_list = []
	for num in str(year):
		if num in numbers_list:
			flag = False
			break
		else:
			numbers_list.append(num)
	if flag:
		print(year)
		sys.exit()


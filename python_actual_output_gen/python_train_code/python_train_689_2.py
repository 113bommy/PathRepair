n = int(input())

for i in range(10)[::-1]:
	if n > int(str(i) + '9'*(len(str(n))-1)):
		print(i + 9*(len(str(n))-1))
		break
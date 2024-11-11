a = input()
n , times = a.split(" ")
for i in range(int(times)):
	if int(n) % 10 == 0:
		n = str(int(n)//10)
	else:
		n = str(int(n)-1)
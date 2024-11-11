
n = int(input())

l = []
k = 1
while int('1' * k + '0' * (k - 1), 2) <= n // 2:
	l.append(int('1' * k + '0' * (k - 1), 2))
	k += 1

for i in range(len(l)):
	if n % l[-(i + 1)] == 0:
		print(l[-(i + 1)])
		exit()
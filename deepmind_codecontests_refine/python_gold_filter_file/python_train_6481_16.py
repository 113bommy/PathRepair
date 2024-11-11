from sys import stdin, stdout

for _ in range(int(stdin.readline())):
	n = int(stdin.readline())
	ls = list(map(int, stdin.readline().split()))
	# ones = 0
	# for i in range(n - 1):
	# 	ones += ls[i] == 1
	f = True
	loss = 0
	can_prevent = 0
	pos = 0
	for i in range(n - 2, -1, -1):
		if ls[i] == 1:
			if i != 0 and ls[i - 1] != 1:
				if loss % 2 == 1:
					loss = 0

			else:
				loss += 1
		else:
			pos += 1
	if loss % 2 == 0:
		print('First')
	else:
		print('Second')
# if f:
# 	stdout.write('First\n')
# else:
# 	stdout.write('Second\n')

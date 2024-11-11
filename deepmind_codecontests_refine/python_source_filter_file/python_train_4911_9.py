n = int(input())
tape = []
for i in range(n):
	temp = [' '] * (n - i)
	for j in range(i):
		temp.append(j)
	temp.append(i)
	for j in range(i - 1, -1, -1):
		temp += str(j)
	temp.append(' ' * (n - 1))
	tape.append(temp)
	print(*tape[-1])
	temp = []
for i in range(n):
	temp.append(i)
temp.append(n)
for i in range(n - 1, -1, -1):
	temp.append(i)
print(*temp)
for i in range(n - 1, -1, -1):
	print(*tape[i])
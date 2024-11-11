
t = int(input())

while t > 0:
	n1, n2 = input().split()
	n1 = int(n1)
	n2 = int(n2)

	lis1 = [int(a) for a in input().split()]
	lis2 = [int(a) for a in input().split()]

	lis1.sort()
	lis2.sort()

	ins = []

	i = 0
	j = 0

	while i<n1 and j<n2:
		if lis1[i] == lis2[j]:
			ins.append(lis1[i])
			i += 1
			j += 1
		elif lis1[i] < lis2[j]: i+=1
		else: j+=1

	if len(ins) == 0:
		print('NO')
	else:
		print('YES')
		print(len(ins), ins[0])

	t -= 1

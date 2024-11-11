
n = int (input())
l1 = [1]* n
l2 =  [int(i) for i in range(1,n+1)]

if n == 1:
	print(1)
	exit()
elif n == 2:
	print(5)
	exit()
for _ in range(n-2):
	l3 = [1]


	for i in range(1,n):
		l3.append(l2[i] + l3[i-1])

	l2 = l3


print(max(l3))


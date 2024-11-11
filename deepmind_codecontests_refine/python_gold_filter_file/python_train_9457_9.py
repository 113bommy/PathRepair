n = int(input())
A = [int(input()) for i in range(n)]
s = sum(A)
if s % 10:
	print(s)
else:
	A.sort()
	for a in A:
		if a % 10:
			print(s - a)
			exit()
	else:
		print(0)
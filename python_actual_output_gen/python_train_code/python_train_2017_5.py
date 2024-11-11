n = int(input())

a = input()
b = input()
c = input()

A = a.split()
B = b.split()
C = c.split()

ax = int(A[0])
ay = int(A[1])
bx = int(B[0])
by = int(B[1])
cx = int(C[0])
cy = int(C[1])

if (bx < ax and cx < ax) or (bx > ax and cx > ax):
	if (by < ay and cy < ay) or (by < ay and cy < ay):
		print('YES')
	else:
		print('NO')
else:
	print('NO')
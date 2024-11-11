n, m, k = map(int, input().split())

done = 0

for A in range(m // n,m+1):

	up = A

	if (k-1) >= (A-1):
		up = up + A * (A-1) / 2
		up = up + k - A
	else:
		s = A - k + 1
		up = up + (s + (A - 1)) * (A - s) / 2


	kk = n - k 

	if (kk-1) >= (A-1):
		up = up + A * (A-1) / 2
		up = up + kk - A
	else:
		s = A - kk
		up = up + (s + (A - 1)) * (A - s) / 2

	if up > m:
		done = 1
		print(A-1)
		break


if done == 0:

	print(m)
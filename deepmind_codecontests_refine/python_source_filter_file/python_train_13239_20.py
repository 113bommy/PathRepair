import math

n = int(input(), 2)
if n == 0:
	print(n)
else:
	f = math.log(n, 4)
	ff = int(4 ** f)
	if f != int(f) or n != ff:
		print(int(f) + 1)
	else:
		print(int(f))

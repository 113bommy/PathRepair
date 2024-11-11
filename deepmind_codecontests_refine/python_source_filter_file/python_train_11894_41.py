import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
import sys

# sys.stdout.write(str(n)+"\n")
p6 = [0, 3, 1, 5, 2, 4]
p7 = [4, 0, 2, 5, 1, 3, 6]
p4 = [1, 3, 0, 2]

t = int(input())
for _ in range(t):
	n = int(input())

	if n <= 3:
		print(-1)
	else:
		next_ = 1

		if n % 4 == 1:
			sys.stdout.write(str(next_) + " ")
			next_ += 1
			n -= 1
		elif n % 4 == 2:
			for i in range(6):
				sys.stdout.write(str(next_ + p6[i]) + " ")
			next_ = 7
			n -= 6 
		elif n % 4 == 3:
			for i in range(6):
				sys.stdout.write(str(next_ + p7[i]) + " ")
			next_ = 8
			n -= 7
		while n > 0:
			for i in range(4):
				sys.stdout.write(str(next_ + p4[i]) + " ")
			next_ += 4
			n -= 4
		sys.stdout.write("\n")

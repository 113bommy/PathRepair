# a = [0 for i in range(100)]

# k = 3

# R = 100

# for i in range(1, R):
# 	if i >= 1:
# 		if a[i-1] == 0:
# 			a[i] += 1
# 	if i >= 2:
# 		if a[i-2] == 0:
# 			a[i] += 1
# 	if i >= k:
# 		if a[i-k] == 0:
# 			a[i] += 1

# for i in range(33):
# 	for j in range(3):
# 		print(a[i*3 + j], end=" ")
# 	print()

from math import ceil

T = int(input())

for _ in range(T):
	N, K = map(int, input().split())
	
	if K%3 == 0:
		row = (N//3)%(K+1)

		if row == K:
			print("Alice")
		else:
			if row % K == N % 3:
				print("Bob")
			else:
				print("Alice")
	else:
		if N%3 == 0:
			print("Bob")
		else:
			print("Alice")



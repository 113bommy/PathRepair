import math
import heapq

N = int(input())

A = list(map(int, input().split()))
B = list(map(int, input().split()))

num = 0
i = 0
comp = 0
for i in range(N):
	if A[i] == B[i]:
		comp += 1
	elif A[i] > B[i]:
		print(-1)
		exit()
i = 0

while comp < N:
	loc = i % N
	loc_plus = (i + 1) % N
	loc_minus = (i - 1) % N
	if B[loc] >= B[loc_plus] and B[loc] >= B[loc_minus] and A[loc] < B[loc]:
		big = max(B[loc_minus], B[loc_plus])
		if big <= A[loc]:
			if (B[loc] - A[loc]) % (B[loc_minus] + B[loc_plus]) == 0:
				comp += 1
				num += (B[loc] - A[loc]) // (B[loc_minus] + B[loc_plus])
				B[loc] = A[loc]
			else:
				print(-1)
				exit()
		else:
			n = math.ceil((B[loc] - big + 1)/(B[loc_minus] + B[loc_plus]))
			num += n
			B[loc] -= n*(B[loc_minus] + B[loc_plus])
			if B[loc] < A[loc]:
				print(-1)
				exit()
			elif B[loc] == A[loc]:
				comp += 1
		if B[loc_plus] > B[loc_minus]:
			i = loc_plus
		else:
			i = loc_minus
	elif (B[loc] < B[loc_plus] or B[loc] < B[loc_minus]) and A[loc] < B[loc]:
		if B[loc_plus] > B[loc_minus]:
			loc_next = loc_plus
		else:
			loc_next = loc_minus
		if B[loc_plus] == A[loc_plus]:
			print(-1)
			exit()
		else:
			i = loc_next
	elif A[loc] == B[loc]:
		i += 1
	#print(B, num, loc)
print(num)
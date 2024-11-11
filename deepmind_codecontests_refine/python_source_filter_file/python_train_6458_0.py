# AOJ ITP2_1_A: Vector
# Python3 2018.6.24 bal4u

from collections import deque
Q = deque()
q = int(input())
for i in range(q):
	a = input()
	if   a[0] == '0': Q.append(a[2:])     # pushBack
	elif a[0] == '1': print(Q[int(a[2])]) # randomAccess
	else:             Q.pop()             # popBack

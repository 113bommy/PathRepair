from collections import deque

D = set()
N = int(input())

for i in range(N):
	c, s = input().split()
	if c == "insert":
		D.append(s)
	elif c == "find":
		if (s in D):
			print("yes")
		else:
			print("no")
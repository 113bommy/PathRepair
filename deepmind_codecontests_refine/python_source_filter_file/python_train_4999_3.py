from collections in deque

N = int(input())

A = deque()

for i in range(N):
	b= input()
	if b == "deleteFirst":
		A.popleft()
	elif b == "deleteLast":
		A.pop()
	else:
		b, c = b.split()
		c = int(c)
	
		if b == "insert":
			A.appendleft(c)
		elif b == "delete":
			if (c in A):
				A.remove(c)

print(" ".join(map(str, A)))
	
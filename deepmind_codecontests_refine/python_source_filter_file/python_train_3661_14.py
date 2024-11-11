from collections import deque

inp = list(map(int, input().split(" ")))
N = int(inp[0])
q = int(inp[1])

A = list(map(int, input().split(" ")))

d = deque(A)

ans = [[] for i in range(N)]

for i in range(N - 1):
	a = d.popleft()
	b = d.popleft()
	ans[i].append(a)
	ans[i].append(b)
	if(a > b):
		d.appendleft(a)
		d.append(b)
	else:
		d.appendleft(b)
		d.append(a)

for i in range(q):
	m = int(input())
	if(m < N):
		print(ans[m - 1][0], ans[m - 1][1])
	else:
		ind = m % (N - 1)
		# print(ind)
		# print(d)
		if(ind == 0):
			ind = N - 2
		print(d[0], d[ind])

N, Q = list(map(int, input().split()))
s = list(input())

D = [0 for i in range(N)]

ql = []
for i in range(Q):
	t, d = list(input().split())
	ql.append([t, d])

x = 0
y = N - 1
for i in range(Q):
	if ql[-1 - i][1] == "L":
		if y < N - 1:
			if ql[-1 - i][0] == s[y + 1]:
				D[y] = 0
				y += 1
		if x < N:
			if ql[-1 - i][0] == s[x]:
				D[x] = 1
				x += 1

	else:
		if x > 0:
			if ql[-1 - i][0] == s[x - 1]:
				D[x] = 0
				x -= 1
		if y >= 0:
			if ql[-1 - i][0] == s[y]:
				D[y] = 1
				y -= 1

print(N - sum(D))
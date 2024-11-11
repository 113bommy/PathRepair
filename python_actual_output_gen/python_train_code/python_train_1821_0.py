import sys

lines = sys.stdin.readlines()

N = int(lines[0])
a = list(map(int, lines[1].split(' ')))
b = [-1 for _ in a]
for i, x in enumerate(a):
	b[x-1] = i
max_len = 0
cur_len = 1
for i in range(1, N):
	if b[i-1] < b[i]:
		cur_len += 1
	else:
		cur_len = 1
	if cur_len > max_len:
		max_len = cur_len
print(N - max_len)





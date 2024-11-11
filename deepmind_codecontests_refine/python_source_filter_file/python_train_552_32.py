n, k = map(int, input().split())
arr = []
for _ in range(n):
	p, t = map(int, input().split())
	arr.append([-p, t])
arr.sort()

cur = [1]
prev = arr[0]
d = {1: cur}

for i, x in enumerate(arr[1:]):
	if x != prev:
		cur = [0]
		prev = x
	if x == prev:
		cur[0] += 1
	d[i + 1] = cur
print(d[k][0])

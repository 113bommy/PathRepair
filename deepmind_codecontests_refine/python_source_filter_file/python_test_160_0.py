count = int(input())

n = [0] * count
m = [0] * count
r = [0] * count
c = [0] * count
r_1 = [0] * count
c_1 = [0] * count

for i in range(count):
	n[i], m[i], r[i], c[i], r_1[i], c_1[i] = map(int, input().split())

def f(n, m, r, c, r_1, c_1):
	t = 0
	dr = 1
	dc = 1
	while r != r_1 and c != c_1:
		if 1 > r + dr or r+ dr > n:
			dr = -1
		if 1 > c + dc or c + dc > m:
			dc = -1
		r = r + dr
		c = c + dc
		t += 1
	print(t)

for i in range(count):
	print(f(n[i], m[i], r[i], c[i], r_1[i], c_1[i]))




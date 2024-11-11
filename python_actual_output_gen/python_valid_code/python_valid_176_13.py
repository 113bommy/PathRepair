mod = 1000000007

def mult(a, b):
	res = [[0, 0], [0, 0]]
	for i in range(2):
		for j in range(2):
			for k in range(2):
				res[i][j] += a[i][k] * b[k][j]
			res[i][j] %= mod
	return res

x, y = [int(x) for x in input().split()]
n = int(input()) - 2
if n == -1:
	print(x)
	exit(0)
m = [[1, -1], [1, 0]]
res = [[1, 0], [0, 1]]
while n:
	if n & 1:
		res = mult(res, m)
	m = mult(m, m)
	n >>= 1
print((res[0][0] * y + res[0][1] * x) % mod)

k, b, n, t = map(int, input().split())
z = int(1)
res = int(n)

for i in range(n):
	z = k*z + b
	if z < t:
		res -= 1
	else:
		break

print(res)
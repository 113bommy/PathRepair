# vars: A, B, k, k1, n, res, x
n = int(input())
k = int(input())
A = int(input())
if k == 1:
	print((n-1)*A)
	exit()
B = int(input())
res = 0
x = n
k1 = (k-1)*A
while x > 1:
	res += A*(x % k)
	x //= k
	if x:
		if B > x * k1:
			res += (x-1)*k*A
			x = 1
		else:
			res += B
print(res-(1-x)*A)
# a, b -> a // b, a % b

n = int(input())

# so my mathematics says that the formula is 3(3^(n-1) + (-1)^(n-1)) / 4
# so we need to take this modulo 10^9 + 7
# surely there should be a reason for such a specific number

'''
ans = 1 # 3(3^(n-1)-(-1)^(n-1))/4
N = 10**9 + 7
for i in range(n):
	ans = (ans * 3) % N

'''

ans = 3
index = 2
N = 10 ** 9 + 7
'''
while ans != 1:
	#print(ans)
	ans = (ans * 3) % N
	index += 1
print(index)
'''

# so, we need to find the smallest n for which 3^n == 1 mod N
# how do we do this...
# so clearly, since N is prime you can take n = N-1 but this is already too big
# ok, the smallest n is (N-1)/2 so we can't do this path
# the other idea is to convert n into binary format, and try to use this instead.
# in that way we can save a lot of repeated calculations.
digits = []
while n != 0:
	digits.append(n % 2)
	n = n // 2
l = len(digits)
power = [3]
for _ in range(l-1):
	power.append((power[-1] ** 2) % N)
ans = 1
for _ in range(l):
	ans *= power[_] ** digits[_]
ans += 3 if digits[0] == 0 else -3
while ans % 4 != 0:
	ans += N
print(int(ans / 4))





'''
def multiply(A,B): #A,B are mxn, nxp matrices
	m = len(A)
	n = len(A[0]) # = len(B)
	p = len(B[0])
	ans = [[0] * p for _ in range(m)]
	for i in range(m):
		for j in range(p):
			ans[i][j] = sum(A[i][k] * B[k][j] for k in range(n))
	return ans
'''
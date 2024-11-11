import sys
sys.setrecursionlimit(10**7)

n = int(input())
#a = list(map(int, input().split()))
MOD = 10 ** 9 + 7

def extended_euclid(x, y):
    c0, c1 = x, y
    a0, a1 = 1, 0
    b0, b1 = 0, 1

    while c1 != 0:
        m = c0 % c1
        q = c0 // c1

        c0, c1 = c1, m
        a0, a1 = a1, (a0 - q * a1)
        b0, b1 = b1, (b0 - q * b1)

    # return c0, a0, b0
    return a0

def quotient(p, q): #p: 分子, q: 分母
	return (extended_euclid(q, MOD) * p) % MOD

def factorial(i):
	if i == 1:
		return 1
	else:
		return (factorial(i-1) * i) % MOD

inv_list = [1]
for i in range(2, n+1):
	inv_list.append((inv_list[-1] + quotient(1, i)) % MOD)

#print(inv_list[-1])
#print(factorial(n))

ans = 0
for i in range(n):
	ans += ((inv_list[i] + inv_list[n-1-i] - 1) * a[i]) % MOD
	ans %= MOD
ans *= factorial(n)
ans %= MOD
print(ans)
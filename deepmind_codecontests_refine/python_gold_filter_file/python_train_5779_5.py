import random

def bpow(a, n, mod):
	res = 1
	while n > 0:
		if n % 2 == 1:
			res = (res * a) % mod
		a = (a * a) % mod
		n //= 2
	return res

def is_prime(p):
	if p <= 1:                                               
		return False
	elif p < 4:
		return True
	else:
		for _ in range(10):
			a = random.randint(2, p - 1)
			if bpow(a, p - 1, p) != 1:
				return False
		return True

if __name__ == "__main__":
	n = int(input())
	p = n
	ans = []
	while not is_prime(p):
		p -= 1
	ans.append(p)
	if n - p == 2:
		ans.append(2)
	else:
		n -= p
		for i in range(2, n + 1):
			if is_prime(i) and is_prime(n - i):
				ans.append(i)
				ans.append(n - i)
				break
	print(len(ans))
	for x in ans:
		print(x, end = ' ')
	
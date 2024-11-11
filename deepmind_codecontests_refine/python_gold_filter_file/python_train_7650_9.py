'''input
6
'''
def is_prime(n):
	if n == 2: return True
	elif n < 2 or n % 2 == 0: return False
	elif all(n % i != 0 for i in range(3, int(n**0.5)+1, 2)): return True
	return False
n, t, l = int(input()), 0, []
for x in range(2, n+1):
	if is_prime(x):
		k = 1
		while x**k <= n:
			l.append(str(x**k))
			k += 1
			t += 1
print(t, " ".join(l), sep="\n")

	
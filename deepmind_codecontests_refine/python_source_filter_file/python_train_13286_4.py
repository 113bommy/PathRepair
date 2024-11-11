
def intersect_size(n, m):
	val = 1
	exponent = n - m
	term = n

	while exponent > 0:
		val *= term
		term -= 1
		exponent -= 1

	return val

mem_comb = {}

def comb(n, k):
	if n < 0 or k < 0 or n < k:
		return 0
	elif k == 0 or k == n:
		return 1
	elif (n, k) not in mem_comb:
		m = 1
		val = 1
		while m <= k:
			val *= (n+1 - k)
			val /= k
			m += 1
		val = round(val)

		mem_comb[(n, k)] = val

	return mem_comb[(n, k)]


def at_least_occurrences(n, k):
	return sum((-1)**j * comb(n-k+j-1, j) * intersect_size(n, n-k+j) for j in range(k+1))


n, k = [int(x) for x in input().split(' ')]

if n == k:
	print(intersect_size(n, 0))
else:
	print(at_least_occurrences(n, k))
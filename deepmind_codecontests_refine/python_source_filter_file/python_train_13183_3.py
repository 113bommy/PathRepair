n, N = input(), input()
N = [i for i in N]
n = sorted((i for i in n), reverse=True)

def has_hal(n, N):
	return sorted(n) < N

def solve(n, N):
	if len(n) < len(N):
		return ''.join(n)
	if not n:
		return ''
	for pos, d in enumerate(n):
		if d > N[0]:
			continue
		if d == N[0]:
			n1 = n[:]
			n1.remove(d)
			if has_hal(n1, N[1:]):
				return d + solve(n1, N[1:])
		if d < N[0]:
			n1 = n[:pos] + n[pos + 1:]
			return d + ''.join(n1)


print(solve(n, N))

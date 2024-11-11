def main():
	(n, k) = (int(x) for x in input().split())
	L = [int(x) for x in input().split()]
	result = solver(n, k, L)
	print(result)

def solver(n, k, L):
	i = quadraticEqPlus(1, 1, -2 * k)
	inti = int(i)
	lastRound = inti * (inti + 1) // 2
	if k - lastRound == 0:
		return L[inti - 1]
	else:
		return L[k - lastRound - 1]

def quadraticEqPlus(a, b, c):
	return (-b + (b**2 - 4 * a * c)**0.5) / (2 * a)

#L = [10, 4, 18, 3]
#print(solver(4, 5, L))
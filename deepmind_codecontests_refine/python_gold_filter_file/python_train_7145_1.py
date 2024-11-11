
n, L = map(int, input().split())
c = [*map(int, input().split())]
rational = [True] * n
for i in range(n):
	for j in range(n):
		if i < j and c[i] >= c[j]:
			rational[i] = False
		if i < j and c[i] * (2 ** (j - i)) <= c[j]:
			rational[j] = False

def dfs(i, L):
	if i == 0: 
		return L * c[0]
	elif rational[i]:
		Li = 2 ** i
		if Li >= L:
			return min(c[i], dfs(i - 1, L))
		else:
			return (L // Li * c[i]) + dfs(i, L % Li)
	else:
		return dfs(i - 1, L)


print(dfs(n - 1, L))
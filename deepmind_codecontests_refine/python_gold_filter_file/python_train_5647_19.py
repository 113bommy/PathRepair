def solve(n,m):
	lettre = "BW"
	if n*m %2 == 1:
		for i in range(m):
			ligne = ""
			for j in range(n):
				ligne += lettre[(i+j)%2]
			print(ligne)
	else:
		l = "B"
		for j in range(n-1):
			l += lettre[j % 2]
		print(l)
		for i in range(m-1):
			ligne = ""
			for j in range(n):
				ligne += lettre[(i+j)%2]
			print(ligne)

t = int(input())
for i in range(t):
	m, n = map(int, input().split())
	solve(n,m)
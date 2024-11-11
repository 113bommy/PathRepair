import sys
#map(int, sys.stdin.readline().split())
#list(map(int, sys.stdin.readline().split()))

t = int(sys.stdin.readline())
for _ in range(t):
	n = int(sys.stdin.readline())
	matrice = [[char for char in sys.stdin.readline()] for i in range(n)]
	out = True
	for l in range(n):
		if not out:
			break
		for c in range(n):
			if not out:
				break
			if matrice[l][c] == "1" and l != n-1 and c != n-1:
				if matrice[l+1][c] == "0" and matrice[l][c+1] == "0":
					out = False
					#print(l, c)
	if out:
		print("YES")
	else:
		print("NO")


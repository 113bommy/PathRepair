n = int(input())
s = input()
MOD = 100000007
A = C = G = T = 0
for c in s:
	A += (c == 'A')
	C += (c == 'C')
	G += (c == 'G')
	T += (c == 'T')
m = max(A, C, G, T)
count = (A == m) + (C == m) + (G == m) + (T == m)
print ((count**n) % MOD)
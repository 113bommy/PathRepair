n = int(input())

if n == 1:
	G = [1]
else:
	G = [g for g in [1, 4, 10, 23, 57, 132, 301, 701] if g < n]
	while True:
		g = int(2.25 * G[-1])
		if g > n:
			break
		G.append(g)
	G.reverse()

A = [int(input()) for _ in range(n)]
cnt = 0
for g in G:
	for j, v in enumerate(A[g:]):
		while j >= 0 and A[j] > v:
			A[j+g] = A[j]
			j -= g
			cnt += 1
		A[j+g] = v

print(len(G))
print(*G)
print(cnt, a*, sep='\n')

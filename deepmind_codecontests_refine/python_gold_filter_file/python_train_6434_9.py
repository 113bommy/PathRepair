N, M = map(int, input().split())
L, R = 1, N
for i in range(M):
	L_i, R_i = map(int, input().split())
	L, R = max(L, L_i), min(R, R_i)

print(max(0, R-L+1))


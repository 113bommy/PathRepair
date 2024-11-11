N,M,K = map(int, input().split())

for i in range(N+1):
	for j in range(M+1):
		if i*(N-j)+j*(M-i) == K:
			print('Yes')
			exit()
print('No')
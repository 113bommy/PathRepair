N, K, S = map(int,input().split())

n = [1]*N
for i in range(K):
  n[i] = S
for i in range(N):
	print(n[i],end=' ')
N, K = map(int, input().split())
A = []
for i in range(K):
  d = input()
  A += list(map(int, input()))
print(N - len(set(A)))
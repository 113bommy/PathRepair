N, M = map(int, input().split())
A = [str(i) for i in range(1 * 10 ** (N - 1), 1 * 10 ** N)]
if N == 1:
  A.append('0')
for i in range(M):
  t = list(map(int, input().split()))
  A = [A[j] for j in range(len(A)) if int(A[j][t[0] - 1]) == t[1]]
print(-1 if (not A) == True else min(A))
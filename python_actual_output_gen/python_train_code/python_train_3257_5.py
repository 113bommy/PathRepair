N, K = map(int, input().split())
A = list(map(int, input().split()))
e = [False] * (N+1)
idx = 1
move = []
while True:
  if e[idx]:
    break
  move.append(idx)
  e[idx] = True
  idx = A[idx-1]
m = move.index(idx)
c = len(move) - m

if K <= m:
    print(D[K])
else:
    print(D[m+(K-m) % c])
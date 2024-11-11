N = int(input())
A = [int(input()) * N + i for i in range(N)]
A.sort()
cnt = 0
for i in range(N):
  d = (A[i] % N) % 2
  if d % 2 == i % 2:
    cnt += 1
print(cnt//2)
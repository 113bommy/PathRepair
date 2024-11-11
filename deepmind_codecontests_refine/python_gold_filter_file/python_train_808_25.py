N = int(input())
A = list(map(int, input().split()))

ans = 0

for k in range(60):
  cnt = [0] * 2
  for i in range(N):
    ans += cnt[(A[i] >> k & 1) ^ 1] << k
    cnt[A[i] >> k & 1] += 1

print(ans % (10 ** 9 + 7))


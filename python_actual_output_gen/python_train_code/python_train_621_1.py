N, K = map(int, input().split())
S = input()
c = 0
for i in range(1, N):
  if s[i] == s[i - 1]:
    c += 1
print(min(N - 1, c + K * 2))

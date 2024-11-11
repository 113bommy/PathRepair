N = int(input())
X = [int(x) for x in input().split()]
p = 10 ** 9 + 7
P = [1 for _ in range(N + 1)]
for i in range(N):
  P[i + 1] = P[i] * (i + 1) % p
T = [N - 1] * N
pos = 0
for i in range(N):
  if 2 * i + 1 - X[i] >= 2 * pos + 1:
    T[pos] = i
    pos += i
cnt = 1
for i, t in enumerate(T):
  cnt *= t + 1 - i
  cnt %= p
print(cnt)
N, K = map(int, input().split())
A = list(map(int, input().split()))

t_zero = [-1] * N

t = 0
a = 1

while t_zero[a-1] == -1:
  if t == K:
    break
  t_zero[a-1] = t
  t += 1
  a = A[a-1]
else:
  k = (K - t_zero[a-1]) % (t - t_zero[a-1])
  a = t_zero.index(t_zero[a-1] + k) + 1
print(a)
N, Q = map(int, input().split())
S = input()
W = [['', ''] for i in range(Q)]
for i in range(Q):
  t, d = input().split()
  W[i] = [t, d]
W.reverse()
cnt = 0
l = 0
r = 0
for t, d in W:
  if t == S[l] and d == 'L':
    l += 1
  elif l > 0 and t == S[l - 1] and d == 'R':
    l -= 1
  elif t == S[N - 1 - r] and d == 'R':
    r += 1
  elif r > 0 and t == S[N - r] and d == 'L':
    r -= 1
  if l + r >= N:
    break
print(N - l - r)
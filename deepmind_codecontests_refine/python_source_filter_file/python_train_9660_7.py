S = input()

N = len(S) + 1
t = [0] * N
p = ''
for i in range(N - 2, -1, -1):
  if p == '>':
    t[i + 1] = t[i + 2] + 1
  p = S[i]
for i in range(N - 1):
  if S[i] == '<':
    t[i + 1] = max(t[i + 1], t[i] + 1)
print(sum(t))

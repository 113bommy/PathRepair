N, K = map(int, input().split(' '))
R, S, P = map(int, input().split(' '))
T = list(input())
print(T)
score = 0
A = T
for i in range(N-K):
  if T[i] == T[i+K]:
    A[i+K] = 'a'

for i in range(N):
  if A[i] == 'r':
    score += P
  elif A[i] == 's':
    score += R
  elif A[i] == 'p':
    score += S
print(score)
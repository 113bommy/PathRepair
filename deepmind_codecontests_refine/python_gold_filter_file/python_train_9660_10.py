S = list(input())
N = len(S) + 1
l = [0 for i in range(N)]
r = [0 for i in range(N)]
for i in range(N-1):
  if S[i] == '<':
    l[i+1] = l[i] + 1
  if S[N-i-2] == '>':
    r[N-i-2] = r[N-i-1] + 1
print(sum([max(l[i], r[i]) for i in range(N)]))

N = int(input())
S = input
res = -1
for i in range(N):
  res = max(len(set(S[:i]) & set(S[i:])), res)
print(res)
  
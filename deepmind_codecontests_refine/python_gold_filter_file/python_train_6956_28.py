from collections import defaultdict

n = int(input())
S = input()
A = S[:n]
B = S[n:][::-1]
Da = defaultdict(int)
Db = defaultdict(int)
ans = 0
for i in range(2**n):
  a1, a2 = "", ""
  for j in range(n):
    if i>>j & 1:
      a1 += A[j]
    else:
      a2 += A[j]
  Da[(a1, a2)] += 1
for i in range(2**n):
  b1, b2 = "", ""
  for j in range(n):
    if i>>j & 1:
      b1 += B[j]
    else:
      b2 += B[j]
  Db[(b1, b2)] += 1

for k in Da:
  ans += Da[k] * Db[k]
print(ans)
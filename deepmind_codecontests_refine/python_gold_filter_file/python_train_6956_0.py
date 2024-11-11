from collections import defaultdict
import sys
input = sys.stdin.readline

n = int(input())
S = input().rstrip()
L = S[:n]
R = S[n:][::-1]
C = defaultdict(int)
ans = 0
for i in range(1<<n):
  l = ""
  r = ""
  for j, s in enumerate(L):
    if i>>j & 1:
      l += s
    else:
      r += s
  C[l+"."+r] += 1
for i in range(1<<n):
  l = ""
  r = ""
  for j, s in enumerate(R):
    if i>>j & 1:
      l += s
    else:
      r += s
  ans += C[l+"."+r]
print(ans)
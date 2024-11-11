import sys
input = sys.stdin.readline

n = int(input())
S = tuple(map(int, input().split()))
ans = 0
for c in range(1, n-1):
  temp = 0
  T = set()
  for k in range(1, n):
    d = c*k
    if d >= n:
      break
    if d == n-1-d or d in T or n-1-d in T:
      break
    T.add(d)
    T.add(n-1-d)
    temp += S[d]+S[n-1-d]
    ans = max(ans, temp)
print(ans)
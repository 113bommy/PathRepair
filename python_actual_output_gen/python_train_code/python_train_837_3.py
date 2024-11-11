n = int(input())
s = input()
ans = s.count('B') * s.coufnt('G') * s.count('R')
for i in range(n):
  for j in range(i, n-1):
    k = 2*j - i
    if k >= n:
      continue
    if s[i] != s[j] and s[i] != s[k] and s[j] != s[k]:
      ans -= 1

print(ans)

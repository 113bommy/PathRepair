from fractions import gcd
n, m = map(int, input().split())
s = input()
t = input()
g = gcd(n, m)
sg, tg = n//g, m//g
for i in range(g-1):
  if s[sg*i] != t[tg*i]:
    print(-1)
    break
else:
  print(sg*m)
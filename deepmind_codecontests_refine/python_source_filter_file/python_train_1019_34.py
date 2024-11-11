_ = input()
S = input().lstrip('.').rstrip('#')
n = len(S)

x = 0
y = S.count('.')
c = min(n-y, y)
for i in range(n):
  t = S[i]=='#':
  x += t
  y -= not t
  c = min(c, x+y)
print(c)
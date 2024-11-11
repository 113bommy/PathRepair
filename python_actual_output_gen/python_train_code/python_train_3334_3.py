s = input()
n = len(s)
a = [0 for i in range(n)]
for i in range(n - 1):
  if s[i] == '<':
    a[i + 1] = max(a[i + 1], a[i] + 1)
for i in reversed(range(n - 1)):
  if s[i] == '>':
    a[i] = max(a[i], a[i + 1] + 1)
ans = sum(a)
#print(ans)
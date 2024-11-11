a, b = str(input()), str(input())
p, s, pp, sp = [0] * len(b), [0] * len(b), 0, len(a) - 1
p[0] = a.find(b[0])
while sp >= 0 and a[sp] != b[-1]:
  sp -= 1
s[len(b) - 1] = sp
pp, sp = p[0] + 1, sp - 1
for i in range(1, len(b)):
  if p[i - 1] == -1:
    p[i] = -1
  else:
    while pp < len(a) and a[pp] != b[i]:
      pp += 1
    p[i] = (pp if pp < len(a) else -1)
    pp += 1
for i in range(len(b) - 2, -1, -1):
  if s[i + 1] == -1:
    s[i] = -1
  else:
    while sp >= 0 and a[sp] != b[i]:
      sp -= 1
    s[i] = (sp if sp >= 0 else -1)
    sp -= 1
anss, ans = 0, (-1, -1, -1)
for i in range(0, len(b)):
  if p[i] == -1:
    break
  while anss < len(b) and (s[anss] <= p[i] or s[anss] == -1) or anss <= i:
    anss += 1
  ln = (i + 1 if p[i] != -1 else 0) + (len(b) - anss if anss < len(b) and s[anss] != -1 else 0)
  if ln > ans[0]:
    ans = (ln, i, anss)
only_s = len(b) - 1
while only_s - 1 >= 0 and s[only_s - 1] >= 0:
	only_s -= 1
if only_s >= 0 and s[-1] > 0 and len(b) - only_s > ans[0]:
  print(b[only_s:])
elif ans[0] == -1:
  print("-")
else:
  print(b[:ans[1] + 1] + (b[ans[2]:] if ans[2] < len(b) else ""))
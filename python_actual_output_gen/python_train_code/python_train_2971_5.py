s = input()
n = len(s)
p = 0
for e in s:
  if e == 'p':
    p += 1
print(s//2 - p)
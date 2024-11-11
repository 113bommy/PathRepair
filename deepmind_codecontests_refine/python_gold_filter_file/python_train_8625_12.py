s = input()

P = 0
for c in s:
  if c == 'p':
    P += 1

print(len(s)//2 - P)
import sys
s = input()
ans = 0
while len(s)>= 2:
  if s[0] == s[-1]:
    s = s[1:-1]
  elif s[0] == 'x':
    ans += 1
    s = s[1:]
  elif s[-1] == 'x':
    ans += 1
    s = s[:-2]
  else:
    print(-1)
    sys.exit()
print(ans)
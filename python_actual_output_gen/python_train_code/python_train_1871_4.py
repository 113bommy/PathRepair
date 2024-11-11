n = int(input())
s = input()

if s[:2/n] == s[2/n:]:
  print('Yes')
else:
  print('No')
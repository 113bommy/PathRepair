n = int(input())
s = input()

if s[:n] == s[n:]:
  print('Yes')
else:
  print('No')
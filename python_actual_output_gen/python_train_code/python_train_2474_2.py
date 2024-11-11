s = input()
n = len(s)
a = s[:(n-1)//2]
b = s[(n+3)//2:]

if a == b and a == a[::-1]:
  print('Yes')
else:
  print('No')
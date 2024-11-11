s = str(input())
n = len(s)
s1 = s[:(n-1)/2]
if s != s[::-1] or s1 != s1[::-1]:
  print('No')
else:
  print('Yes')
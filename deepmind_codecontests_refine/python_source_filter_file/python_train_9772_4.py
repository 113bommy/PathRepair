s = list(input())
if 'N' in s and 'S' in s or not ('N' in s or 'S' in s) and ('E' in s and 'W' in s or not ('E' in s or 'W' in s)):
  print('Yes')
else:
  print('No')
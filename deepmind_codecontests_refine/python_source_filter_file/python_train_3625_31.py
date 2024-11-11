s = input()

if s[0] == 'A' and s[2:-2].count('C') == 1 and sum(x.isupper() for x in s) == 2:
  print('AC')
else:
  print('WA')
s=input()
if s[0] =='A' and s[2:-1].count('C') ==1 and s[1:].replace('C', '').islower:
  print('AC')
else:
  print('WA')
s=input()
if list(s)==list(set(list(s))):
  print('yes')
else:
  print('no')
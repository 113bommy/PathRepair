s = input()

def f(a,b):
  return (a in s and b not in s) or (b in s and a not in s)
  
if f('W', 'E') or f('N', 'S'):
  print('No')
else:
  print('Yes')


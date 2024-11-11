s=input()
N=len(s)
if s[0]==s[-1]:
  if N%2:
    print('Second')
  else:
    print('First')
else:
  if N%2:
    print('First')
  else:
    print('Second')
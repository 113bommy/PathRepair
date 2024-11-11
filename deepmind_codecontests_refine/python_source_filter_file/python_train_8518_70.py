import re
akb_re = re.compile(r'A?KIHA?BA?RA?$')

s = input()
mo = akb_re.match(s)
if mo == None:
  print('No')
else:
  print('Yes')

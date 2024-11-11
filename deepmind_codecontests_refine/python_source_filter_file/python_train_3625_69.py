import re

S = input()
matchObj = re.match(r'^A[a-z]C{1}[a-z]*[a-z]$', S)
if matchObj:
    print('AC')
else:
    print('WA')

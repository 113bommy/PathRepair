import re

S = input()
matchObj = re.match(r'^A[a-z]C[a-z]*[a-z]$', S)
if matchObj:
    print('AC')
else:
    print('WA')

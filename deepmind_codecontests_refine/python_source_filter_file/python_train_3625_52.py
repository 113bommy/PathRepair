import re
p = re.compile(r'A[a-z]{1,}C[a-z]{1,}')

S = input()
if bool(p.match(S)):
    print('AC')
else:
    print('WA')

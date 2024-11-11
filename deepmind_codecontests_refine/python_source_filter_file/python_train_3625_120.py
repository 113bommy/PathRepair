import re

s = input()
reg = re.match('[A][a-z]+[C][a-z]{2}', s)
if reg:
    print('AC')
else:
    print('WA')

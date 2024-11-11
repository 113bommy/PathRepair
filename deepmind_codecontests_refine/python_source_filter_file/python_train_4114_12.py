import re

ss = re.split(r'\W', input())

a = []
b = []
for w in ss:
    if w.isnumeric() and (w == '0' or w[0] != '0'):
        a.append(w)
    else:
        b.append(w)

if a:
    print('"%s"' % ",".join(a))
else:
    print("-")
if b:
    print('"%s"' % ",".join(b))
else:
    print("-")

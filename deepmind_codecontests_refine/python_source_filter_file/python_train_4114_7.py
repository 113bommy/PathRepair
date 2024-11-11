import re

s = input()
a = ''
b = ''

splitted = re.split('[;,\.]', s)
for st in splitted:
	if (st.isdigit() and st[0] != '0' or st == '0'):
		a += st + ','
	else:
		b += st + ','

if len(a):
    print('"' + a[:-1] +'"')
else:
    print('-')

if len(b):
    print('"' + b[:-1] +'"')
else:
    print('-')

import re

ip = input()

k = ip.split(';')
f=','.join(k)
f = f.split(',')
a=[]
b=[]
for ele in f:
    k = re.match('^[^0a-zA-Z][0-9]+$', ele)
    m = re.match('^[0-9]$', ele)
    if k:
        a.append(k.group(0))
    elif m:
        a.append(m.group(0))
    else:
        b.append(ele)
if len(a) == 0:
    print('-')
else:
    print("\""+ ','.join(a) +"\"")
if len(b) == 0:
    print('-')
else:
    print("\""+ ','.join(b) +"\"")
import re

s = input()
l = re.split(r'[,;.]', s)
ln = list(filter(lambda x: x.isdigit() and x[0] != '-' and (x=='0' or x[0]!='0'), l))
ls = list(filter(lambda x: not (x.isdigit() and x[0] != '-' and (x=='0' or x[0]!='0')), l))
print('"'+','.join(ln)+'"' if len(ln) != 0 else '-')
print('"'+','.join(ls)+'"' if len(ls) != 0 else '-')

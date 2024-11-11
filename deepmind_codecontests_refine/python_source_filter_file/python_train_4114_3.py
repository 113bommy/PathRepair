ls = input().replace(';',',').split(',')
ls1, ls2 = [], []
[ ls1.append(x) if (x.isdigit() and not (x[0]=='0' and len(x)>1)) else ls2.append(x) for x in ls]
s1, s2 = ','.join(ls1), ','.join(ls2)
if (len(s1)):
    print('"' + s1 + '"')
else:
    print('-')
if (len(s2)):
    print('"' + s2 + '"')
else:
    print('-')

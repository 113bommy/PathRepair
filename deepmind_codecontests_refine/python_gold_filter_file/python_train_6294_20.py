d = {'A':0,'B':0,'C':0}

for i in range(3):
    s = input()
    a = s[0]
    b = s[2]
    sign = s[1]
    
    if sign == '>':
        d[a] += 1
    else:
        d[b] += 1

if [item[1] for item in sorted(zip(d.keys(),d.values()), key=lambda x: x[1])] != [0,1,2]:
    print('Impossible')
else:
    print(''.join(sorted(d, key=d.get)))
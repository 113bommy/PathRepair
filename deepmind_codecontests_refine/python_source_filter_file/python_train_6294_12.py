a = []
for i in range(3):
    a.append(input())
d = {'A':[], 'B':[], 'C':[]}
for s in a:
    if s[1] == '<':
        d[s[0]].append(s[2])
    else:
        d[s[2]].append(s[0])
res = [0, 0, 0]
possible = True
for key in d.keys():
    pos = 2 - len(d[key])
    if res[pos] != 0:
        possible = False
        break
    else:
        res[pos] = key
if possible:
    print(''.join(res))
else:
    print('IMPOSSIBLE')
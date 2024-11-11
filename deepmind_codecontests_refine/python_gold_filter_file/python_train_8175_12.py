import sys
m = dict(A='A', b='d', d='b', H = 'H', I='I', M='M', O='O', o='o', p = 'q', q = 'p', T='T', U='U', V='V', v='v', W='W', w='w', X='X',
         x='x', Y='Y')
s = input()
ans = ''
if len(s) == 1:
    if s in m:
        print('TAK')
        sys.exit()
    else:
        print('NIE')
        sys.exit()
if len(s) % 2 != 0:
    k = s[0: len(s)//2 + 1]
    t = s[(len(s)//2):]
    for i in range(len(k) -1, -1, -1):
        if k[i] in m:
            ans += m[k[i]]
        else:
            break
else:
    k = s[0:len(s)//2]
    t = s[len(s)//2:]
    for i in range(len(k) -1, -1, -1):
        if k[i] in m:
            ans += m[k[i]]
        else:
            break
if ans == t:
    print('TAK')
else:
    print('NIE')
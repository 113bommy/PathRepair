import re

s = input().strip()
t = re.sub('[^AbdHIMOopqTUVvWwXxY]{1}', '', s)

m = {}
for i in range(ord('A'), ord('z') + 1):
    m[chr(i)] = chr(i)

m['b'] = 'd'
m['d'] = 'b'
m['p'] = 'q'
m['q'] = 'p'

def is_sp():
    sl = len(t)
    for i in range(sl // 2 + 1):
        if m[t[i]] != t[sl - 1 - i]:
            return False
    return True

if len(t) == len(s):
    if is_sp():
        print('TAK')
    else:
        print('NIE')
else:
    print('NIE')

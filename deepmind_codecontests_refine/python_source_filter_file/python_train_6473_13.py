import math
n = input()
s = input()
s += ' '
crnt = ''
a = []
count = 0
for i in s:
    if i == ' ':
        a += [int(crnt)]
        crnt = ''
        continue
    crnt += i
for i in a:
    if i % 2 == 0:
        f = True
    else:
        f = False
        break
for i in a:
    if i % 2 == 1:
        f = True
    else:
        f = False
        break
if not f:
    c = []
    b = []
    for i in a:
        if i % 2 == 0:
            b += [i]
        else:
            c += [i]
    #print(b, c)
    max_len = max(len(b), len(c))
    print(max_len-1)
else:
    print(0)
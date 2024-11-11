# HEY STALKER
from collections import Counter
s = input()
t = input()
k = 0
ii = 0
jj = 0
while 1:
    if t[ii] == s[jj]:
        ii += 1
        jj += 1
    else:
        jj += 1
    if ii == len(t) or jj == len(s):
        break
if ii == len(t):
    print("automaton")
else:
    xt = Counter(t)
    xs = Counter(s)
    p = 1
    c = 1
    for i in xt:
        if i not in xs:
            c = 0
            break
        if xs[i] < xt[i]:
            p = 0
            break
    if c == 0:
        print("need tree")
    elif p:
        if len(s) == len(t):
            print("array")
        else:
            print("both")
    else:
        print("need tree")
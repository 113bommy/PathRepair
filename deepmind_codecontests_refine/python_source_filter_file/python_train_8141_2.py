'''input
4
onetwone
testme
oneoneone
twotwo
'''

from sys import stdin
import math
def input():
    return stdin.readline()[:-1]

for _ in range(int(input())):
    s = list(input())
    pos = []
    i = 0
    while i+2 < len(s):
        if s[i] == 'o' and s[i+1] == 'n' and s[i+2] == 'e':
            pos.append(i+1)
            i += 3
        elif i+4 < len(s) and s[i] == 't' and s[i+1] == 'w' and s[i+2] == 'o' and s[i+3] == 'n' and s[i+4] == 'e':
            pos.append(i+2+1)
            i += 5
        elif s[i] == 't' and s[i+1] == 'w' and s[i+2] == 'o':
            pos.append(i+1)
            i += 3
        else:
            i += 1
    print(len(pos))
    print(' '.join(map(str,pos)))


#!/usr/bin/python3

import sys

z = []
i = 1
p = -1

d = sys.stdin.read(1)
while d == '0' or d == '1':
    if d == '0':
        if p == -1:
            z.append([i])
        else:
            z[p].append(i)
            p -= 1
    else:
        if p == len(z) - 1:
            p = 0
            break
        else:
            z[p + 1].append(i)
            p += 1

    i += 1
    d = sys.stdin.read(1)

if p == -1:
    sys.stdout.write(str(len(z)) + '\n')
    for zz in z:
        sys.stdout.write(str(len(zz)) + ' ' + ' '.join(map(str, zz)) + '\n')
else:
    sys.stdout.write('-1\n')

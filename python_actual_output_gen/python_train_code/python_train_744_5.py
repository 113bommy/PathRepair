#!/usr/bin/env python
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))


if len(c) > 1:
    print('No')
else:
    for i in range(a[0] - 1):
        x = b[i]
        y = b[i+1]
        if x == 0:
            x = c[0]
        if y == 0:
            y = c[0]
        if x > y:
            print('No')
            break
    else:
        print('Yes')

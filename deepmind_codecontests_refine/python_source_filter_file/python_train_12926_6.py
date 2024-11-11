#! /usr/bin/env python3
# -*- coding: UTF-8 -*-
line = input()
need = int(line.split(' ')[1]) - 1
n = int(line.split(' ')[0])
s = input()

if need == 1:
    print(0)
else:
    queue = [s]
    d = {}
    head, tail, ans = 0, 1, 0
    solve = False

    while head < tail and not solve:
        top = queue[head]
        cost = len(top)-1
        for idx, c in enumerate(top):
            new = ''.join([top[:idx], top[idx + 1:]])
            h = new.__hash__()
            if not d.get(h):
                d[h] = 1
                queue.append(new)
                tail += 1
                ans += n - cost
                need -= 1
                if need == 0:
                    solve = True
                    break
        head += 1

    if not solve:
        print("-1")
    else:
        print(ans)

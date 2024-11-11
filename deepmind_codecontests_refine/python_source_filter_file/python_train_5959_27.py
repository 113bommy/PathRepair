# -*- coding: utf-8 -*-

n, m, k = map(int, input().split())
res = ['D'*(n-1), 'R'*(m-1)]
if n < m:
    g_left = 'L'*(n-1)
    g_right = 'R'*(n-1)
    up = 'U'
    s = [g_left, up, g_right, up]
    counter = 0
    for k in range(2*n-1):
        res.append(s[counter])
        counter += 1
        if counter == 4:
            counter = 0
else:
    v_up = 'U'*(m-1)
    v_down = 'D'*(m-1)
    left = 'L'
    s = [v_up, left, v_down, left]
    counter = 0
    for k in range(2*m-1):
        res.append(s[counter])
        counter += 1
        if counter == 4:
            counter = 0

r = ''.join(res)
print(len(r))
print(r)
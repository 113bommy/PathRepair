from collections import deque

n, p, k = [int(x) for x in input().split()]
nav = [x for x in range(p - k, (p + k) + 1)]

nav_str = '<<' if nav[0] > 1 else ''
for e in nav:
    if e > n:
        break
    elif e >= 1:
        nav_str += ' ' + str(e)

print(nav_str.replace(' {} '.format(p), ' ({}) '.format(p)).strip() + (' >>' if nav[-1] < n else ''))
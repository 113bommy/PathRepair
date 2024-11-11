from collections import namedtuple
n = int(input())
Show = namedtuple('Show', 'time sign')
shows = []
for _ in range(n):
    time1, time2 = map(int, input().split())
    shows.append(Show(time1, 'b'))
    shows.append(Show(time2, 'a'))

tv = 0
for show in sorted(shows):
    if show.sign == 'b':
        tv += 1
    else:
        tv -= 1
    if tv > 2:
        print('NO')
        exit(0)
print('YES')

"""
5
1 2
2 3
2 5
1 2
5 6
"""

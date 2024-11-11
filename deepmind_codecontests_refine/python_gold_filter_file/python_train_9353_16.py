import bisect
from operator import add, sub

n, l, t = map(int, input().split())

ope = [None, add, sub]
ants = [tuple(map(int, input().split())) for _ in range(n)]
ants_pos = [ope[w](x, t) % l for x, w in ants]

if n == 1:
    print(ants_pos[0])
    exit()

x0, w0 = ants[0]
crash_cnt = 0
crash_check = (lambda x: t - (x - x0) / 2) if w0 == 1 else (lambda x: t - (l - x + x0) / 2)
for x, w in ants[1:]:
    if w == w0:
        continue
    d = crash_check(x)
    if d >= 0:
        crash_cnt += 2 * d // l + 1

ant_alt0 = (0, 1, -1)[w0] * int(crash_cnt) % n
sorted_pos = sorted(ants_pos)
pos_i = bisect.bisect_left(sorted_pos, ants_pos[0])
if pos_i < n - 1 and sorted_pos[pos_i] == sorted_pos[pos_i + 1] and w0 == 1:
    pos_i += 1
pos0_i = (pos_i - ant_alt0) % n
for pos in sorted_pos[pos0_i:]:
    print(pos)
for pos in sorted_pos[:pos0_i]:
    print(pos)

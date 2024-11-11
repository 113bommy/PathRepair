from operator import itemgetter
import bisect


h, w, n = map(int, input().split())
info = [tuple(map(int, input().split())) for i in range(n)]

memo = set()
for i, j in info:
    memo.add(i * 10**6 + j)

pos = [[] for _ in range(w + 1)]
info = sorted(info, key = itemgetter(1))
for i, j in info:
    pos[j].append(i)

ans = 10**18
pos_i, pos_j = 1, 1

ind = bisect.bisect_right(pos[pos_j], pos_i)
try:
    ans = min(pos[pos_j][ind] - 1, ans)
except:
    pass

while True:
    if (pos_i + 1) * 10**6 + pos_j in memo or pos_i == h:
        ans = min(ans, pos_i)
        break
    pos_i += 1

    if pos_i * 10**6 + (pos_j + 1) in memo or pos_j == w:
        continue
    else:
        pos_j += 1

    ind = bisect.bisect_right(pos[pos_j], pos_i)
    try:
        ans = min(pos[pos_j][ind] - 1, ans)
    except:
        pass
print(ans)
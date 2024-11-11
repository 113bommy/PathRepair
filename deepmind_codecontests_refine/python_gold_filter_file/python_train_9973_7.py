import math
from operator import itemgetter


n = int(input())
info = [list(map(int, input().split())) for i in range(n)]

for i in range(n):
    tmp = math.atan2(info[i][1], info[i][0])
    info[i].append(tmp)

info = sorted(info, key = itemgetter(2))
info = info + info
ans = 0

for i in range(n):
    tmp = [0, 0]
    for j in range(n):
        tmp[0] += info[i+j][0]
        tmp[1] += info[i+j][1]
        tmp_ans = tmp[0]**2 + tmp[1]**2
        ans = max(tmp_ans, ans)

print(ans**0.5)
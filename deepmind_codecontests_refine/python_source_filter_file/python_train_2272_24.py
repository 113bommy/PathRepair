from collections import Counter
from itertools import permutations

N, C = map(int, input().split())
D = [list(map(int, input().split())) for i in range(C)]
c = [list(map(lambda s: int(s) - 1, input().split())) for i in range(N)]

d = [Counter(sum([c[j][(i - j) % 3::3] for j in range(N)], []))
     for i in range(3)]
ans = 1000000
for t in permutations(range(C), 3):
    dis = 0
    for i in range(3):
        for k, v in d[i].items():
            dis += D[k][t[i]] * v
    ans = min(dis, ans)
print(ans)

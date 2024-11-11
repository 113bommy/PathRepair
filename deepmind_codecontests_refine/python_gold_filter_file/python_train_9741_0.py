from math import gcd

def DFS(v):
    re = 0
    cur = v
    while not used[cur]:
        used[cur] = True
        re += 1
        cur = gr[cur]
    if re % 2 == 0:
        re //= 2
    return 0 if cur != v else re

n = int(input())
used = [False] * (n + 1)
gr = [0] + list(map(int, input().split()))
res = 1
for u in range(1, len(gr)):
    if not used[u]:
        r = DFS(u)
        if r:
            res = (res * r) // gcd(res, r)
        else:
            print(-1)
            exit()
print(res)
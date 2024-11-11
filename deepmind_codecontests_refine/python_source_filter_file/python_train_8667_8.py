import sys
import math

ii = lambda: int(sys.stdin.buffer.readline().rstrip())
il = lambda: list(map(int, sys.stdin.buffer.readline().split()))
fl = lambda: list(map(float, sys.stdin.buffer.readline().split()))
iln = lambda n: [int(sys.stdin.buffer.readline().rstrip()) for _ in range(n)]

iss = lambda: sys.stdin.buffer.readline().decode().rstrip()
sl = lambda: list(map(str, sys.stdin.buffer.readline().decode().split()))
isn = lambda n: [sys.stdin.buffer.readline().decode().rstrip() for _ in range(n)]

n = ii()
a = il()
q = ii()
cnt = [0] * (10 ** 5 + 1)
cnt_246 = [0, 0, 0, 0]
lis = [2, 4, 6, 8]
for i in range(n):
    cnt[a[i]] += 1
    if cnt[a[i]] in lis:
        cnt_246[lis.index(cnt[a[i]])] += 1
        # print(i, cnt_246)

for qu in range(q):
    s = iss()
    # print(len(s), s)
    if s[0] == "+":
        cnt[int(s[-1])] += 1
        if cnt[int(s[-1])] in lis:
            cnt_246[lis.index(cnt[int(s[-1])])] += 1
    else:
        cnt[int(s[-1])] -= 1
        if cnt[int(s[-1])] + 1 in lis:
            cnt_246[lis.index(cnt[int(s[-1])] + 1)] -= 1
    # print(cnt_246, cnt[:3])
    if (
        cnt_246[3] >= 1
        or cnt_246[2] >= 2
        or (cnt_246[2] >= 1 and sum(cnt_246[:3]) >= 4)
        or (cnt_246[1] >= 2)
        or (cnt_246[1] == 1 and cnt_246[0] >= 3)
    ):
        print("YES")
    else:
        print("NO")

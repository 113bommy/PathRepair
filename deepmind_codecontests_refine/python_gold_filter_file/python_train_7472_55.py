def Yes():
    print('Yes')
    exit()


def No():
    print('No')
    exit()


def parse(s):
    ret = [0, 0]
    for c in s:
        if c == ')':
            if ret[0]:
                ret[0] -= 1
            else:
                ret[1] -= 1
        else:
            ret[0] += 1
    return ret


N = int(input())
S = [parse(input()) for _ in range(N)]
S.sort(key=lambda a: -a[0] - a[1])
S1 = sorted([s for s in S if s[0] + s[1] >= 0], key=lambda a: -a[1])
S2 = sorted([s for s in S if s[0] + s[1] < 0], key=lambda a: -a[0])
cnt = 0
for s in S1:
    cnt += s[1]
    if cnt < 0:
        No()
    cnt += s[0]
for s in S2:
    cnt += s[1]
    if cnt < 0:
        No()
    cnt += s[0]
if cnt:
    No()
Yes()

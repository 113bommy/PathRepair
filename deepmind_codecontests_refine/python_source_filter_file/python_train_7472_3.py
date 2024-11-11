n = int(input())
lr1, lr2 = [], []
res = 0
for _ in range(n):
    s = input()
    m = len(s)

    l, r = 0, 0
    tmp = 0
    for i in range(m):
        if s[i] == ')':
            tmp += 1
        else:
            tmp -= 1
        l = max(l, tmp)
    tmp = 0
    for i in range(m):
        if s[m-1-i] == '(':
            tmp += 1
        else:
            tmp -= 1
        r = max(r, tmp)

    res += r - l
    if r - l >= 0:
        lr1.append((l, r))
    else:
        lr2.append((l, r))

if res != 0:
    print('No')
    exit()

lr1.sort(key=lambda x: -x[0])
lr2.sort(key=lambda x: -x[1])

flg1, flg2 = True, True

n1, n2 = len(lr1), len(lr2)
tmp = 0
for i in range(n1):
    l, r = lr1[i]
    tmp -= l
    if tmp < 0:
        flg1 = False
    tmp += r

tmp = 0
for i in range(n2):
    l, r = lr2[i]
    tmp -= r
    if tmp < 0:
        flg2 = False
    tmp += l

if flg1 and flg2:
    print('Yes')

else:
    print('No')
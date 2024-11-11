n = int(input())
a = list(map(int, input().split()))

d = {}

for ai in a:
    if ai not in d:
        d[ai] = 0
    d[ai] += 1

f = 1

k = list(d.keys())
k.sort()

# ボッチ猫の数
b = 0

if len(k) > 2:
    f = 0
elif len(k) == 2:
    if k[1] - k[0] != 1:
        f = 0
    b = d[k[0]]

# グループ数
g = k[-1] - b

if g == 0 or g > d[k[-1]] // 2:
    f = 0

if b == 0 and k[-1] == n - 1:
    f = 1

if f:
    print('Yes')
else:
    print('No')

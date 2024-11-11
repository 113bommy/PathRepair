n = int(input())

pre = 999999
segs = []

for x in map(int, input().split()):
    if pre != 999999:
        segs.append((min(pre, x), max(pre, x)))
    pre = x

segs.sort()

intersect = False

for i in range(0, len(segs)):
    for j in range(i, len(segs)):
        if segs[i][1] < segs[j][1] and segs[i][0] < segs[j][0]:
            intersect = True
            break

print('yes' if intersect else 'no')

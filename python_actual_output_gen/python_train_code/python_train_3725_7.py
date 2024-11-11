n, r = (int(i) for i in input().split())
neg_change = []
pos_change = []
for _ in range(n):
    a, b = (int(i) for i in input().split())
    if b < 0:
        neg_change.append((a, b))
    else:
        if r >= a:
            r += b
        else:
            pos_change.append((a, b))
# print(neg_change)
# print(pos_change)
pos_change.sort()
possible = True
for i, j in pos_change:
    if r >= i:
        r += j
    else:
        possible = False
        break
if possible:
    func = lambda i: i[0]+i[1]
    neg_change.sort(key=func, reverse=True)
    for i, j in neg_change:
        if r > 0 and r >= i:
            r += j
        else:
            possible = False
            break
print("YNEOS"[not possible::2])

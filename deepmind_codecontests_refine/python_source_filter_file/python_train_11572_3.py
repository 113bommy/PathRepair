from collections import defaultdict
n = int(input())
l = input()
r = input()
d_l = defaultdict(list)
d_r = defaultdict(list)
for i in range(n):
    d_l[l[i]].append(i+1)
    d_r[r[i]].append(i+1)

indices = []
for i in range(97, 97+26):
    c = chr(i)
    m = min(len(d_l[c]), len(d_r[c]))
    for _ in range(m):
        i1 = d_l[c].pop()
        i2 = d_r[c].pop()
        indices.append((i1, i2))

flag1 = True
flag2 = True
for i in range(97, 97+26):
    c = chr(i)
    tmp1 = len(d_l[c])
    tmp2 = len(d_r[c])
    for _ in range(tmp1):
        if d_r["?"] == []:
            flag1 = False
            break

        if flag1:
            i1 = d_l[c].pop()
            i2 = d_r["?"].pop()
            indices.append((i1, i2))
    
    for _ in range(tmp2):
        if d_l["?"] == []:
            flag2 = False
            break

        if flag2:
            i1 = d_r[c].pop()
            i2 = d_l["?"].pop()
            indices.append((i1, i2))

    if flag1 or flag2:
        continue
    else:
        break

m = min(len(d_l["?"]), len(d_r["?"]))
for _ in range(m):
    i1 = d_l["?"].pop()
    i2 = d_r["?"].pop()
    indices.append((i1, i2))

k = len(indices)
print(k)
for _ in range(k):
    print(*indices[_])

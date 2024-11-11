s = input()
a = list(map(int, s[:3]))
b = list(map(int, s[3:]))
al = sum(a)
bl = sum(b)
dif = al - bl
cnt = 0
while dif < 0:
    cnt += 1
    if 9 - min(a) > max(b):
        dif += min(-dif, 9 - min(a))
        a[a.index(min(a))] = 9
    else:
        dif += min(-dif, max(b))
        b[b.index(max(b))] = 0

c = b[:]
b = a[:]
a = c[:]
while dif > 0:
    cnt += 1
    if 9 - min(a) > max(b):
        dif += min(-dif, 9 - min(a))
        a[a.index(min(a))] = 9
    else:
        dif += min(-dif, max(b))
        b[b.index(max(b))] = 0

print(cnt)
n = int(input())
a = []
alll = []
for i in range(n):
    a += [list(map(str, input().split()))]
a += [[]]
a += [[]]
t = 0
while t != 1000:
    dt = str(t)
    if len(dt) == 1 and dt in a[0] + a[1] + a[2]:
        pass
    elif len(dt) == 1:
        break
    if len(dt) == 2:
        tt = False
        for i in range(3):
            j, k = 0, 0
            while j == i:
                j += 1
            while k == i or k == j:
                k += 1
            if dt[0] in a[i] and (dt[1] in a[j] or dt[1] in a[k]):
                tt = True
        if not tt:
            break
    if len(dt) == 3:
        tt = False
        for i in range(3):
            for j in range(i + 1, 3):
                k = 0
                while k == i or k == j:
                    k += 1
                if dt[0] in a[i] and dt[1] in a[j] and dt[2] in a[k]:
                    tt = True
        if not tt:
            break

    t += 1
print(t - 1)

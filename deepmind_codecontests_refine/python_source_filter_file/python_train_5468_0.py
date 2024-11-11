n,m = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
manager = []
for i in range(m):
    t = [int(j) for j in input().split()]
    manager.append(t)
    j = len(manager) - 1
    while j>0 and len(manager)>1:
        if manager[j][1] > manager[j - 1][1]:
            del(manager[j-1])
            j -= 1
        else: break
temp = a[manager[0][1]:]
temp.reverse()
result = temp
del(a[manager[0][1]:])
a.sort()
lm = len(manager)
l,r = 0,0
for i in range(lm):
    if i < lm - 1:
        if manager[i][0] == 1:
            for j in range(manager[i][1] - manager[i + 1][1]):
                result.append(a[-(1 + r)])
                r += 1
        elif manager[i][0] == 2:
            for j in range(manager[i][1] - manager[i + 1][1]):
                result.append(a[l])
                l += 1
    else:
        if r != 0:
            tem = a[l:-(1 + r)]
        else:
            tem = a[l:]
        if manager[i][0] == 1:
            tem.reverse()
            result.extend(tem)
        elif manager[i][0] == 2:
            result.extend(tem)
result.reverse()
print(*result)

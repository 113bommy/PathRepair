n = int(input())
s = []
for _ in range(n):
    s.append(input())
a = []
b = []
c = []
for i in s:
    mi = 0
    tmp = 0
    for j in i:
        if j=='(':
            tmp += 1
        else:
            tmp -= 1
        if tmp<mi:
            mi = tmp
    if tmp>0:
        a.append((mi, tmp))
    elif tmp==0:
        b.append((mi, tmp))
    else:
        c.append((mi, tmp))
a.sort(key=lambda x:-x[0])
c.sort(key=lambda x:(x[0], -x[1]))
tmp = 0
for i, j in a+b+c:
    if tmp+i<0:
        print('No')
        break
    tmp += j
else:
    if tmp==0:
        print('Yes')
    else:
        print('No')
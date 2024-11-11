#import sys
#sys.stdin = open('in', 'r')
#n = int(input())
#a = [int(x) for x in input().split()]
#n,m = map(int, input().split())

s1 = input()
s2 = input()
l1 = len(s1)
l2 = len(s2)

dl = {}
dr = {}

i1 = 0
i2 = 0

while i1 < l1 and i2 < l2:
    while i1 < l1 and s1[i1] != s2[i2]:
        i1 += 1
    if i1 < l1:
        dl[i2] = i1
        i2 += 1
        i1 += 1

lmax = i2
if lmax == l2:
    print(s2)
else:
    i1 = l1 - 1
    i2 = l2 - 1
    while i1 >= 0 and i2 >= 0:
        while i1 >= 0 and s1[i1] != s2[i2]:
            i1 -= 1
        if i1 >= 0:
            dr[i2] = i1
            i2 -= 1
            i1 -= 1
    rmax = i2

    le = -1
    re = -1
    if l2 - lmax < rmax + 1:
        rcnt = l2 - lmax
        ls = 0
        rs = lmax
    else:
        rcnt = rmax + 1
        ls = rmax + 1
        rs = l2
    rr = rmax + 1
    for ll in range(lmax):
        while rr < l2 and (rr <= ll or dl[ll] >= dr[rr]):
            rr += 1
        if rr < l2:
            dif = rr - ll - 1
            if dif < rcnt:
                rcnt = dif
                ls = 0
                rs = ll + 1
                le = rr
                re = l2

    result = s2[ls:rs]
    if le != -1:
        result += s2[le:re]
    print(result if len(result) > 0 else '-')



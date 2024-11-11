import sys
# from math import ceil,floor,tan
import bisect

RI = lambda : [int(x) for x in sys.stdin.readline().split()]
ri = lambda : sys.stdin.readline().strip()


n = int(ri())
cnt = 0
mina = []
maxa = []
for _ in range(n):
    temp = RI()
    l = temp[0]
    a = temp[1:]
    minn = -1
    maxx = -1
    flag  =False
    for i in range(len(a)):
        if a[i] > minn and i != 0:
            flag = True
        if i == 0 :
            minn = a[i]
            maxx = a[i]
        else:
            minn = min(minn,a[i])
            maxx = max(maxx,a[i])
        

    if flag :
        cnt+=1
    else:   
        mina.append(minn)
        maxa.append(maxx)
mina.sort()
maxa.sort()
# print(mina)
# print(maxa)
ans = 0
for i in range(len(mina)):

    pos = bisect.bisect_right(maxa,mina[i])
    # print(pos)
    ans+=(len(maxa)-pos)

# print(ans)
temp = n-cnt
ans+=(cnt*(2*temp) + cnt*cnt)

print(ans)
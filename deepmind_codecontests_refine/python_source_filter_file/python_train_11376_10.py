def mi():
    return map(int, input().split())
from bisect import bisect_right as br
eps = 1e-6
for _ in range(int(input())):
    n, l = mi()
    a = [0]+list(mi())+[l]
    n+=2
    tt1 = [0]*n
    s1 = [1]*n
    tt1[0] = a[0]
    speed = 1
    for i in range(1, n):
        tt1[i] = tt1[i-1]+(a[i]-a[i-1])/speed
        s1[i] = speed+1
        speed+=1
    b = a.copy()[::-1]

    tt2 = [0]*n
    tt2[0] = b[0] = l-b[0]
    speed = 1
    for i in range(1, n):
        b[i] = l-b[i]
        tt2[i] = tt2[i-1]+(b[i]-b[i-1])/speed
        speed+=1
    '''
1
2 10
1 9

'''
    lo = 0
    hi = l

    while True:
        mid = (lo+hi)/2
        i1 = br(tt1,mid)-1
        pos1 = a[i1]+(mid-tt1[i1])*s1[i1]
        i2 = br(tt2,mid)-1
        pos2 = b[i2]+(mid-tt2[i2])*s1[i2]
        pos2 = l-pos2               
        if pos1-pos2>eps:
            hi = mid
        elif pos2-pos1>eps:
            lo = mid
        else:
            ans = mid
            print('ans', ans)
            break

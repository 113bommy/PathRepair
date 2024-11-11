from collections import deque
MAX = 0
MIN = 0
n,k,q = [int(i) for i in input().split()]

nn = {}
m = [int(i) for i in input().split()]
kk = []
for i in range(1,n+1):
    nn[m[i-1]] = 0

def app(i):
    global MAX,MIN
    v = m[i-1]
    if len(kk) < k:
        kk.append(v)
        return True
    elif len(kk) == k:
        kk.sort()
        MAX = kk[k-1]
        MIN = kk[0]
        if v<MIN:return False
        else:
            kk.append(v)
            c = kk.pop(0)
            nn[c] -=1
            return True

for i in range(q):
    qq = [int(i) for i in input().split()]
    if qq[0] ==1:
        nn[m[qq[1]-1]] = 1
        if app(qq[1]):
            nn[m[qq[1]-1]] = 2
    if qq[0] ==2:
        if nn[m[qq[1]-1]]==2:
            print('YES')
        else:print('NO')



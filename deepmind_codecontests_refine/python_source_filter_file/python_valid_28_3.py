import sys
import math
input = sys.stdin.readline
imp = 'IMPOSSIBLE'


t = int(input())

for test in range(t):
    n, m = list(map(int, input().split(" ")))
    a = list(map(int, input().split(" ")))
    poc = [0 for i in range(n)]
    for i in range(n):
        kk = (i + 1 - a[i]) % n
        poc[kk] += 1
    #print(poc)
    moz = []
    for i in range(n):
        if poc[i] >= n - 2 * m:
            moz.append(i)
    #print(moz)
    ine = []
    res = []
    for mo in moz:
        ine = []
        for i in range(mo, n):
            if (i + 1 - a[i]) % n != mo:
                ine.append(a[i])
        for i in range(mo):
            if (i + 1 - a[i]) % n != mo:
                ine.append(a[i])
        #print(ine)
        sorine = sorted(enumerate(ine), key=lambda x: x[1])
        #print(sorine)
        convine = [0 for i in range(len(ine))]
        for i in range(len(ine)):
            convine[sorine[i][0]] = i + 1
        #print(convine)
        jo = [0 for i in range(len(ine))]
        i = 0
        sets = 0
        while i < len(ine):
            #print(i, jo)
            if jo[i]:
                i += 1
            else:
                sets += 1
                k = i
                jo[k] = 1
                while convine[k] != i + 1:
                    k = convine[k] - 1
                    jo[k] = 1
                    print(k)
                i += 1
        #print(sets, 'sets')
        if len(ine) - sets <= m:
            res.append(str(mo))
    print(str(len(res)) + ' ' + ' '.join(res))




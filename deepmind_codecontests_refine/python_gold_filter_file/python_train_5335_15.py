t = int(input())
while t:
    n = int(input())
    a = list(map(int,input().split()))
    l = len(a)
    i = j = tas = tbs = pbs = bs = 0
    tm = 1
    als = a[i]
    while i <= l-j-1 and i < l and j < l:
        if i >= 1 and i <= l-j-1:
            als = a[i]
            tm += 1
            if pbs >= als:
                while pbs >= als and i < l-j-1:
                    i += 1
                    als += a[i]

        if i < l-j-1:
            bs = a[l-j-1]
            tm += 1
            if als >= bs:
                while als >= bs and l-j-2 > i:
                    j += 1
                    bs += a[l-j-1]
        i += 1
        j += 1
        tas += als
        tbs += bs
        pbs = bs
        als = 0
        bs = 0
    print(tm,end=' ')
    print(tas,end=' ')
    print(tbs)
    t =t - 1

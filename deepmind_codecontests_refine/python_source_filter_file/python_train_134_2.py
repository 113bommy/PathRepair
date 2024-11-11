lst = list(map(int, input().split()))
t = lst[0]
for j in range(t):
    res = []
    lst = list(map(str, input().split()))
    lst1 = list(map(int, input().split()))
    k = lst1[0]
    n = lst1[1]
    m = lst1[2]
    lst2 = list(map(int, input().split()))
    lst3 = list(map(int, input().split()))
    i1 = 0
    i2 = 0
    okey = True
    for i in range(n + m):
        ok = False
        if (i1 < n):
            if (lst2[i1] == 0):
                res = res + ['0']
                k = k + 1
                i1 = i1 + 1
                ok = True
            elif (lst2[i1] <= k):
                res = res + [str(lst2[i1])]
                i1 = i1 + 1
                ok = True      
        if ((i2 < m) and (ok == False)):
            if (lst3[i2] == 0):
                res = res + ['0']
                k = k + 1
                i2 = i2 + 1
                ok = True
            elif (lst3[i2] <= k):
                res = res + [str(lst3[i2])] 
                i2 = i2 + 1
                ok = True
        if (ok == False):
            okey = False
    if (okey):
        #print(res)
        print(' '.join(res))
    else:
        print(-1, res)
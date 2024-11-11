n = int(input())
ss = [int(i) for i in input().split()]
k = ss.copy()
kk = sum(ss)
alice = ss[0]
if ss[0] > kk//2:
    print(1)
    print(1)
else:
    k = k[1:]
    ind = [1,]
    coal = ss[0]
    kkk = 'No'
    for i in range(0,len(k)):
        if 2*k[i] <= ss[0]:
            coal += k[i]
            ind.append(i+2)
            if coal > kk//2:
                kkk = 'Yes'
                break
    if kkk == 'Yes':
        print(len(ind))
        print(*ind)
    else:
        print(0)

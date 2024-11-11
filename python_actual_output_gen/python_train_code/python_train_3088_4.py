N = int(input())

for i in range(N):
    n = int(input())
    lis = list(map(int, input().split()))

    sm = [0]

    for i in lis:
        if i==1:
            sm.append(sm[-1]+1)
        else:
            sm.append(sm[-1]-1)

    dif = sm[-1]

    dic = {}
    res = 2*n
    for i in range(n+1):
        dic[sm[i]] = i

    for i in range(n, 2*n):
        if sm[i]-dif in dic:
            res = min(res, i-dic[sm[i]-dif])
    print(res)

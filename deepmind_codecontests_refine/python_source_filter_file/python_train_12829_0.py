import sys

Ri = lambda : [int(x) for x in sys.stdin.readline().split()]
ri = lambda : sys.stdin.readline().strip()
def list2d(a, b, c): return [[c] * b for i in range(a)]

for _ in range(int(ri())):
    n = int(ri())
    a = Ri()
    count = list2d(201,len(a)+1,0)
    for i in range(len(a)):
        for j in range(1,201):
            count[j][i+1] = count[j][i]
        count[a[i]][i+1]+=1
    dic = {}
    for i in range(len(a)):
        if a[i] in dic:
            dic[a[i]].append(i)
        else:
            dic[a[i]] = [i]
    ans = -1
    for i in dic:
        lis = dic[i]
        l = 0
        r = len(lis)-1
        tans = 1
        while l < r:
            left = lis[l]
            right = lis[r]
            tmax = 0
            for j in range(1,200):
                    cnt =  count[j][right]-count[j][left+1]
                    tmax = max(tmax,cnt)
            tans = max(tans,(l+1)*2 + tmax)
            l+=1
            r-=1
        ans = max(ans,tans)
    # print(ans)
    # for i in range(len(a)):
    #     for j in range(i+1,len(a)):
    #         if a[i] == a[j]:
    #             left = count[a[i]][i+1]
    #             right = count[a[i]][len(a)] - count[a[i]][j]
    #             maxx = 0
    #             for k in range(1,27):
    #                 if k != a[i]:
    #                     cnt = count[k][j+1]-count[k][i]
    #                     maxx = max(maxx,cnt)
    #             ans = max(ans,min(left,right)*2+maxx)

    for i in range(1,201):
        ans = max(ans,count[i][n])
    print(ans)


    
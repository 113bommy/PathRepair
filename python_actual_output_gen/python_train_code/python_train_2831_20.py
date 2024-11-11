t = int(input())
for _ in range(t):
    n = int(input())
    l = sorted(list(map(int,input().split())))
    hval = l[-1]
    flag = 0
    for i in range(1,hval+1):
        l2 = []
        for j in l:
            l2.append(i^j)
        if(l == sorted(l2)):
            flag = 1
            print(i)
            break
    if(flag == 0):
        print(-1)


